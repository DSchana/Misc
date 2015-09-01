// app.js

var express = require('express'),
	path = require('path'),
	cookieParser = require('cookie-parser'),
	session = require('express-session'),
	config = require('./config/config.js'),
	connectMongo = require('connect-mongo')(session),
	mongoose = require('mongoose').connect(config.dbURL),
	passport = require('passport'),
	facebookStrategy = require('passport-facebook').Strategy,
	app = express();

app.set('views', path.join(__dirname, 'views'));
app.engine('html', require('hogan-express'));
app.set('view engine', 'html');
app.use(express.static(path.join(__dirname, 'public')));
app.use(cookieParser());
var env = process.env.NODE_ENV || 'development';
if (env === 'development') {
	// Dev specific settings
	app.use(session({secret:config.sessionSecret}));
} else {
	// Producyion specific setting
	app.use(session({
		secret:config.sessionSecret,
		store: new connectMongo({
			// url:config.dbURL,
			mongoose_connection:mongoose.connections[0],
			stringify:true
		})
	}));
}

app.use(passport.initialize());
app.use(passport.session());

require('./auth/passportAuth.js')(passport, facebookStrategy, config, mongoose);
require('./routes/routes.js')(express, app, passport);

app.listen(3000, function() {
	console.log('ChatCAT working on port 3000');
	console.log('Mode: ' + env);
})