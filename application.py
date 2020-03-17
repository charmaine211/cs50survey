import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks

    Displays an HTML table summarizing, for the user currently logged in, which stocks the user owns, the numbers of shares owned, the current price of each stock, and the total value of each holding (i.e., shares times price). Also display the user’s current cash balance along with a grand total (i.e., stocks’ total value plus cash)."""

    user_id = session["user_id"]

    symbol = db.execute("SELECT DISTINCT symbol FROM stocks WHERE user_id = :user_id", user_id = user_id)

    nr_symbols = len(symbol)

    stock = []
    total_value = 0
    total_symbols = 0

    for i in range(nr_symbols):
        # Returns a list containing 1 dict "SUM(amount)"
        amount_negative = db.execute("SELECT SUM(amount) FROM stocks WHERE symbol = :symbol AND user_id = :user_id AND amount < 0" , symbol = symbol[i]["symbol"], user_id = user_id)[0]["SUM(amount)"]

        amount_positive = db.execute("SELECT SUM(amount) FROM stocks WHERE symbol = :symbol AND user_id = :user_id AND amount > 0", symbol = symbol[i]["symbol"], user_id = user_id)[0]["SUM(amount)"]

        if amount_negative == None:
            amount = amount_positive

        else:
            amount = amount_negative + amount_positive

        # When client doesn't have stock but did own it once
        if amount > 0:
            name = lookup(symbol[i]["symbol"])["name"]
            current_price = lookup(symbol[i]["symbol"])["price"]
            value = round(amount * current_price, 2)
            stock.append([name, amount, current_price, value])
            total_value = total_value + value
            total_symbols = total_symbols + 1

    # Returns a list with 1 dict "cash", rounded it to 2 numbers after comma
    current_balance = round(db.execute("SELECT cash FROM users WHERE id = :user_id", user_id = user_id)[0]["cash"], 2)

    # Return current_balance, stock (a list containg lists with the stock info) and nr_symbols (number of symbols)
    return render_template("index.html", current_balance = current_balance, stock = stock, total_symbols = total_symbols, total_value = total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    """Buy shares of stock"""

    # User reached route via GET
    if request.method == "GET":

        # Display quote
        return render_template("buy.html")

    # User reached route via POST
    else:

        buy_symbol = request.form.get("buy_symbol").upper()
        buy_amount = float(request.form.get("buy_amount"))

        quote_dict = lookup(buy_symbol)

        # Ensure user input is valid
        if quote_dict == None:
            return apology("Please provide a valid symbol", 403)

        if buy_amount < 1:
            return apology("You can only buy a positive amount. To sell, please go to sell", 403)

        stock_price = float(quote_dict["price"])

        user_id = session["user_id"]

        cash_list = db.execute("SELECT cash FROM users WHERE id= :user_id", user_id = user_id)
        cash = float(cash_list[0]['cash'])

        current_cash = cash - (stock_price * buy_amount)

        if current_cash < 0:
            return apology("You don't have enough cash to buy stock", 403)

        db.execute("INSERT INTO stocks (symbol, price, amount, user_id) VALUES (:symbol, :price, :amount, :user_id)", {"symbol": buy_symbol, "price": stock_price, "amount": buy_amount, "user_id": user_id})

        db.execute("UPDATE users SET cash = :current_cash WHERE id = :user_id", {"current_cash": current_cash, "user_id": user_id})

        # Redirect user to home page
        return redirect("/")

@app.route("/history")
@login_required
def history():

    """Show history of transactions """
    user_id = session["user_id"]

    history_list = db.execute("SELECT symbol, price, amount, timestamp FROM stocks WHERE user_id = :user_id", user_id = user_id)

    rows = len(history_list)

    history = []

    for row in range(rows-1, -1, -1):
        history.append([history_list[row]["symbol"], history_list[row]["amount"], history_list[row]["price"], history_list[row]["timestamp"]])

    return render_template("history.html", history = history, rows = rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User reached route via GET
    if request.method == "GET":

        # Display quote
        return render_template("quote.html")

    # User reached route via POST
    else:

        symbol = request.form.get("symbol")

        quote_dict = lookup(symbol)

        # Ensure user input is valid
        if quote_dict == None:
            return apology("Please provide a valid symbol", 403)

        # Display the quote for requested symbol
        return render_template("quoted.html", name = quote_dict["name"], price = quote_dict["price"], quoted_symbol = quote_dict["symbol"])


@app.route("/register", methods=["GET", "POST"])
def register():
    # Forget any user_id
    session.clear()

    """ PROVIDE USERNAME """

    # User reached route via GET
    if request.method == "GET":

        # Display registration form
        return render_template("register.html")

    # User reached route via POST
    else:

        # Query database for username
        username_list = db.execute("SELECT username FROM users")

        # Ensure username was submitted or not already in list
        new_username = request.form.get("username")

        # Check if user has provided a new username
        if len(new_username) == 0:
            return apology("Please choose a username", 403)

        # Check if username is already exists.
        for row in username_list:
            if row["username"] == new_username:
                return apology("Sorry, this username has already been taken. Try something else", 403)

        """ PROVIDE PASSWORD """

        characters = ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '<', '>', '[', ']', '{','}','|',';',':','§','±','€']

        # Ask for a password
        password = request.form.get("password")

        # Check if password valid
        if not len(password) > 7:
            return apology("Password has to be at least 8 characters long", 403)

        elif not any(spec_char in characters for spec_char in password):
            return apology("Password has to have at least 1 special character", 403)

        elif not any(char.isdigit() for char in password):
            return apology("Password has to contain at least 1 number", 403)

        elif not any(char.isupper() for char in password):
            return apology("Password has to contain at least 1 capitalized character", 403)

        # Apology if password and confirmation aren't the same
        elif not request.form.get("confirmation") == password:
            return apology("Passwords do not match", 403)

        """ INSERT NEW USER IN DB"""

        # Hash password
        hash_password = generate_password_hash(password, "sha256")

        # Insert username & hash in users
        db.execute("INSERT INTO users (username, hash) VALUES (:new_username, :hash_password)", {"new_username": new_username, "hash_password": hash_password})

        return redirect ("/")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via GET
    if request.method == "GET":

        # Display quote
        return render_template("sell.html")

    # User reached route via POST
    else:

        sell_symbol = request.form.get("sell_symbol").upper()
        sell_amount = float(request.form.get("sell_amount"))

        temp_symbol = []

        if sell_amount < 1:
            return apology("You can only sell a positive amount. To buy, please go to buy", 403)

        user_id = session["user_id"]

        # Check if client owns stock
        symbol = db.execute("SELECT DISTINCT symbol FROM stocks WHERE user_id = :user_id", user_id = user_id)
        amount = db.execute("SELECT SUM(amount) FROM stocks WHERE symbol = :symbol", symbol = sell_symbol)

        for i in range(len(symbol)):
            temp_symbol.append(symbol[i]["symbol"])

        if sell_symbol not in temp_symbol:
            return apology("Sorry, you don't own this stock", 403)

        if amount[0]["SUM(amount)"] < sell_amount:
            return apology("Sorry, you don't have enough stocks", 403)

        stock_price = float(lookup(sell_symbol)["price"])

        # Returns a list
        cash_list = db.execute("SELECT cash FROM users WHERE id= :user_id", user_id = user_id)
        cash = float(cash_list[0]['cash'])

        current_cash = cash + (sell_amount * stock_price)

        db.execute("INSERT INTO stocks (symbol, price, amount, user_id) VALUES (:symbol, :price, :amount, :user_id)", {"symbol": sell_symbol, "price": stock_price, "amount": (-1 * sell_amount), "user_id": user_id})

        db.execute("UPDATE users SET cash = :current_cash WHERE id = :user_id", {"current_cash": current_cash, "user_id": user_id})

        # Redirect user to home page
        return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
