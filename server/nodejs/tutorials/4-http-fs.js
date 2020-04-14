var http = require('http');
var fs = require('fs');

var server = http.createServer();

server.on('request', function (req, res) {

  var url = req.url;

	if (url === '/') {
		fs.readFile('./index.html', function (err, data) {
      if (err) {
        res.setHeader('Content-Type', 'text/plain; charset=utf-8')
        res.end("File not found!")
      } else {
        // data default type is binary data, data.tostring() can convert to string.
        // res.end() only supprt twe data types, 1: binary, 2: string.
        res.setHeader('Content-Type', 'text/html; charset=utf-8')
        res.end(data)
      }
    })
	} else if (url === '/plain') {
    res.setHeader('Content-Type', 'text/plain; charset=utf-8');
		res.end('hello 世界');

  } else if (url === '/html') {
    res.setHeader('Content-Type', 'text/html; charset=utf-8');
		res.end('<p>hello html <a href="">点我</a></p>');

  } else if (url == '/image') {
		fs.readFile('./chrome.jpg', function (err, data) {
      if (err) {
        res.setHeader('Content-Type', 'text/plain; charset=utf-8');
        res.end("File not found!");
      } else {
        res.setHeader('Content-Type', 'image/jpeg');
        res.end(data);
      }
    })
	}
})

server.listen(3000, function () {
	console.log("server started on http://127.0.0.1:" + 3000);
})