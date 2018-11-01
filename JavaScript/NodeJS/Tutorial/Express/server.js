var express = require("express")
var app = express()

app.use(express.static("public"))

app.get("/", (req, res) => {
	console.log("GET request for /")
	res.send("Hello GET")
})

app.post("/", (req, res) => {
	console.log("POST request for /")
	res.send("Hello POST")
})

app.delete("/del_user", (req, res) => {
	console.log("DELETE request for /del_user")
	res.send("Hello DELETE")
})

app.get("/list_users", (req, res) => {
	console.log("GET request for  /list_users")
	res.send("Page listing")
})

app.get("/ab*cd", (req, res) => {
	console.log("GET request for /ab*dc")
	res.send("Page pattern matching")
})

// Launch server
var server = app.listen(8000, () => {
	var host = server.address().address
	var port = server.address().port

	console.log("App is listening at %s:%s", host, port)
})
