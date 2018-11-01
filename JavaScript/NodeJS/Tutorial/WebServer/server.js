var http = require("http")
var fs = require("fs")
var url = require("url")

// Create server
http.createServer((req, res) => {
	// Parse request with file name
	var path_name = url.parse(req.url).pathname
	console.log("Request for " + path_name + " received")

	fs.readFile(path_name.substr(1), (err, data) => {
		if (err) {
			console.log(err)
			res.writeHead(404, { "Content-Type": "text/html" })
		}
		else {
			res.writeHead(200, { "Content-Type": "text/html" })
			res.write(data.toString())
		}

		res.end()  // Send response body
	})
}).listen(8000)

console.log("Server running at localhost:8000")
