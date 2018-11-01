var buf = Buffer.alloc(30);
var len = buf.write("Simply easy learning");
var json = buf.toJSON(buf);

console.log("Octets written: " + len);
console.log(json);
