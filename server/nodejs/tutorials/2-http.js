/**
 * The HTTP module are designed to support many features of the protocol which have been traditionally difficult to use
 */
var http = require('http');


var server = http.createServer();

server.on('request', function (req, res) {
	console.log("recevice a request!");
	var url = req.url;
	var ip = req.socket.remoteAddress;
	var port = req.socket.remotePort;
	console.log("request url: " + url + " - ip: " + ip + " port: " + port);

  if (url === '/') {
		res.write("index");
		res.write(" page");
		res.end('index page');

  } else if (url === '/login') {
		res.end('login page');

  } else if (url === '/test') {
    var tests = [{
        key11: 'value1',
        key12: 12
      },
      {
        key21: 'value2',
        key22: 22
      }
    ]
		res.end(JSON.stringify(tests));

  } else {
    res.end('404 Not Found.');
  }

})

server.listen(3000, function () {
  console.log("server started on http://127.0.0.1:3000/");
})