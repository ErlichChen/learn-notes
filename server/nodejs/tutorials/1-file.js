/**
 * The fs module provides an API for interacting with the file system in a manner closely modeled around standard POSIX functions.
 */

var fs = require('fs')

fs.writeFile('./test.txt', '123123', 'utf8', function (err) {
  if (err) throw err;
  console.log('The file has been saved!');
});

fs.readFile('./test.txt', function (err, data) {
	if (err) throw err;
	console.log(data);
	console.log(data.toString());
});