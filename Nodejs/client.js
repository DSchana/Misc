// client .js

var net = require("net");
var client = net.createConnection(5000, "localhost");

client.on("data", function(data) {
	console.log(data.toString());
});

client.write("Yo");
client.end();