var local_strategy = require("passport-local").Strategy

var User = require("../app/models/User")

module.exports = (passport) => {
	// Passport session setup
	passport.serializeUser((u, done) => {
		done(null, u.id)
	})

	passport.deserializeUser((id, done) => {
		User.findById(id, (err, u) => {
			done(err, u)
		})
	})

	// Local signup setup
	passport.use("local-signup", new local_strategy({
		usernameField: "email",
		passwordField: "password",
		passReqToCallBack: true
	},
	function(req, email, password, done) {
		console.log("Signing up auth ") //+ email + " " + password)

		process.nextTick(() => {
			console.log("1")
			User.findOne({ "local.email": email }, (err, u) => {
				console.log("2")
				if (err)
					return done(err)

				if (u) {
					return done(null, false, req.flash("signup_message", "That email is already taken"))
				}
				else {
					var new_user = new User();

					new_user.local.email = email
					new_user.local.password = new_user.generateHash(password)

					// New User
					new_user.save((err) => {
						if (err)
							throw err
						return done(null, new_user)
					})
				}
			})
		})
	}))

	// Local login setup
	passport.use("local-login", new local_strategy({
		usernameField: "email",
		passwordField: "password",
		passReqToCallBack: true
	},
	function(req, email, password, done) {
		User.findOne({ "local.email": email }, (err, u) => {
			if (err)
				return done(err)

			if (!u)
				return done(null, false, req.flash("login_message", "No user found"))

			if (!u.validPassword(password))
				return done(null, false, req.flash("login_message", "OOps! Wrong password"))

			return done(null, u)
		})
	}))
}
