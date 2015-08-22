// client .js

var net = require("net");
var readline = require("readline");
var client = net.createConnection(5000, "localhost");

var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

client.on("data", function(data) {
	console.log(data.toString());
});

client.write("Yo");
client.end();