var http = require('http');
var template = require('art-template');
var fs = require('fs');

var server = http.createServer();

server.on('request', function (req, res) {
	var url = req.url

	fs.readFile('./template.html', function (err, data) {
		if (err) {
			return console.log('404 Not Found.')
		}

		var ret = template.render(data.toString(), {
			name: 'Jack',
			age: 18,
			province: '北京市',
			hobbies: [
				'写代码',
				'唱歌',
				'打游戏'
			],
			title: '个人信息'
		})

		res.end(ret);
	})
})

server.listen(3000, function () {
  console.log('The server has started on Http://127.0.0.1:' + 3000);
})
