var http = require("http")

var options = {
	host: "localhost",
	port: "8000",
	path: "/index.html"
}

var callback = (res) => {
	var body = ""

	res.on("data", (data) => {
		body += data
	})

	res.on("end", () => {
		console.log(body)
	})
}

var req = http.request(options, callback)
req.end()
