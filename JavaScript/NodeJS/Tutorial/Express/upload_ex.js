var express = require("express")
var fs = require("fs")
var body_parser = require("body-parser")
var multer = require("multer")

var app = express()

app.use(express.static("public"))
app.use(body_parser.urlencoded({ extended: false }))

upload = multer({ dest: "/tmp/" })

app.get("/index.html", (req, res) => {
	res.sendFile(__dirname + "/index.html")
})

app.post("/file_upload", (req, res) => {
	console.log(req.files.file.name)
	console.log(req.files.file.path)
	console.log(req.files.file.type)
	var file = __dirname + "/" + req.files.file.name

	fs.readFile(req.files.file.path, (err, data) => {
		fs.writeFile(file, data, (err) => {
			if (err) {
				console.log(err)
			}
			else {
				response = {
					message: "File uploaded successfully",
					filename: req.files.file.name
				}
			}

			console.log(response)
			res.end(JSON.stringify(response))
		})
	})
})

var server = app.listen(8000, () => {
	var host = server.address().address
	var port = server.address().port

	console.log("Example app listening at http://%s:%s", host, port)
})
