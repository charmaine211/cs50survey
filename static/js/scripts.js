function login(){
    let username = document.querySelector("#username").value;
    let password = document.querySelector("#password").value;

    if (username ==='' || password === '')
    {
        alert("Please provide a username and password");
        return false;
    }
}

function register(){
    let username = document.querySelector("#username").value;
    let password = document.querySelector("#password").value;
    let confirmation =  document.querySelector("#confirmation").value;

    var errors = [];
    let special_char = ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '<', '>', '[', ']', '{','}','|',';',':','§','±','€'];

    if (username ==='' || password === '' || confirmation === ''){
        alert("Please provide a username, password and confirm your password");
        return false;
    }
    if (password.length < 8) {
        errors.push("Your password must be at least 8 characters");
    }
    if (password.search(/[a-z]/i) < 0) {
        errors.push("Your password must contain at least one letter.");
    }
    if (password.search(/[A-Z]/) < 0) {
        errors.push("Your password must contain at least one uppercase letter.");
    }
    if (password.search(/[0-9]/) < 0) {
        errors.push("Your password must contain at least one digit.");
    }
    if (password.search(special_char) < 0) {
        errors.push("Your password must contain at least one special character.");
    }
    if (password !== confirmation) {
        errors.push("Your password and password confirmation don't match.");
    }
    if (errors.length > 0) {
        alert(errors.join("\n"));
        return false;
    }
}

function pos_integer(){
    var integer = document.querySelector("#integer").value;

    if (integer < 1){
        alert("You can only sell or buy more than 1");
        return false;
    }
}