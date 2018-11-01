var express = require("express")
var body_parser = require("body-parser")
var app = express()

var url_encoded_parser = body_parser.urlencoded({ extended: false })

app.use(express.static("public"))

app.get("/index.html", (req, res) => {
	res.sendFile(__dirname + "/index.html")
})

app.post("/process_post", url_encoded_parser, (req, res) => {
	response = {
		first_name: req.body.first_name,
		last_name: req.body.last_name
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
