// server.js

var cons = [];
var getID = function() {
	return Math.floor(Math.random()*500)+1
}

var net = require("net");
var server = net.createServer(function(c) {
	console.log("Nigga in da hood");

	c.id = getID();
	cons.push(c);

	c.on("data", function(data) {
		var str = data.toString().split(" ");
		console.log(str);
	});
	c.on("close", function() {
		console.log("Nigga got shot");
	});
	c.on("error", function(err) {
		console.log(err);
	});
});

server.listen(5000);