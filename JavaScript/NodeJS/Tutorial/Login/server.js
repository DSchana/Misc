var express = require("express")
var app = express()
var port = process.env.PORT || 8080
var mongoose = require("mongoose")
var passport = require("passport")
var flash = require("connect-flash")
var morgan = require("morgan")
var cookie_parser = require("cookie-parser")
var body_parser = require("body-parser")
var session = require("express-session")
var configDB = require("./config/database.js")

mongoose.connect(configDB.url)

//require("./config/passport")(passport)  // Passport for configuration

// Setup express app
app.use(morgan("dev"))    // Log requests to console
app.use(cookie_parser())  // Read cookies
app.use(body_parser())    // Get information from html forms

app.set("view engine", "ejs")

// Required for passport
app.use(session({ secret: "pythonisbetterthanjs" }))
app.use(passport.initialize())
app.use(passport.session())  // Persistent login session
app.use(flash())

// Load routes, pass in app and fully configured passport
require("./app/routes.js")(app, passport)

// Launch server
app.listen(port)
console.log("Server listening on port " + port)
