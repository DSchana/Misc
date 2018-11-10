module.exports = (app, passport) => {
	// Home page
	app.get("/", (req, res) => {
		res.render("index.ejs")
	})

	// Login page
	app.get("/login", (req, res) => {
		res.render("login.ejs", { message: req.flash("login_message") })
	})

	app.post("/login", passport.authenticate("local-login", {
		successRedirect: "/profile",
		failureRedirect: "/login",
		failureFlash: true
	}))

	// Signup
	app.get("/signup", (req, res) => {
		res.render("signup.ejs", { message: req.flash("signup_message") })
	})

	app.post("/signup", passport.authenticate("local-signup", {
		successRedirect: "/profile",
		failureRedirect: "/signup",
		failureFlash: true  // Allow flash messages
	}))

	// Profile
	app.get("/profile", isLoggedIn, (req, res) => {
		res.render("profile.ejs", { user: req.user })
	})

	// Logout
	app.get("/logout", (req, res) => {
		req.logout()
		res.redirect("/")
	})

	// Route middleware to make sure a user is logged in
	function isLoggedIn(req, res, next) {
		if (req.isAuthenticated())
			return next()
		res.redirect("/")
	}
}
