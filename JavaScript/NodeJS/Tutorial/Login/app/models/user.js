var mongoose = require("mongoose")
var bcrypt = require("bcrypt-nodejs")

var user_schema = mongoose.Schema({
	local: {
		email: String,
		password: String
	},
	facebook: {
		id: String,
		token: String,
		name: String,
		email: String
	},
	twitter: {
		id: String,
		token: String,
		display_name: String,
		username: String
	},
	google: {
		id: String,
		token: String,
		email: String,
		name: String
	}
})

// Generating a hash
user_schema.methods.generateHash = (password) => {
	return bcrypt.hashSync(password, bcrypt.genSaltSync(8), null)
}

// Check if password is valid
user_schema.methods.validPassword = (password) => {
	return bcrypt.compareSync(password, this.local.password)
}

// Create user's model for app
module.exports = mongoose.model("User", user_schema)
