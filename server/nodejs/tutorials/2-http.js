/**
 * The HTTP module are designed to support many features of the protocol which have been traditionally difficult to use
 */
var http = require('http');


var server = http.createServer();

server.on('request', function () {
  console.log("recevice a request!");
})

server.listen(3000, function () {
  console.log("server started on http://127.0.0.1:3000/");
})