var express = require("express")
var app = express()

// GET Method
app.get("/index.html", (req, res) => {
	res.sendFile(__dirname + "/index.html")
})

app.get("/process_get", (req, res) => {
	response = {
		first_name: req.query.first_name,
		last_name: req.query.last_name
	}

	console.log(response)
	res.end(JSON.stringify(response))
})

// Launch server
var server = app.listen(8000, () => {
	var host = server.address().address
	var port = server.address().port

	console.log("App is listening at %s:%s", host, port)
})
