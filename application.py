import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    name = request.form.get("name")
    house = request.form.get("house")
    role = request.form.get("role")
    if not name or not house or not role:
        return render_template("error.html", message="Please enter all your information")
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((name, house, role))
    file.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():

    # Registrants
    names = []
    houses = []
    roles = []

    with open('survey.csv', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        rowcounter = 0

        for row in reader:
            names.append(row['name'])
            houses.append(row['house'])
            roles.append(row['role'])
            rowcounter = rowcounter + 1

    return render_template("sheet.html", rowcounter=rowcounter, names=names, houses=houses, roles=roles)