var express = require("express")
var fs = require("fs")

var app = express()

app.get("/users", (req, res) => {
	fs.readFile(__dirname + "/users.json", "utf8", (err, data) => {
		if (err) {
			console.log(err)
		}
		else {
			console.log(data)
			res.end(data)
		}
	})
})

app.get("/users/:id", (req, res) => {
	fs.readFile(__dirname + "users.json", "utf8", (err, data) => {
		var users = JSON.parse(data)
		var user = users["user" + req.params.id]
		console.log(user)
		res.end(JSON.stringify(user))
	})
})

var server = app.listen(8000, () => {
	var host = server.address().address
	var port = server.address().port

	console.log("Example app listening at http://%s:%s", host, port)
})
