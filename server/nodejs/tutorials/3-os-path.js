/**
 * The os module provides operating system-related utility methods and properties.
 */

var os = require('os');

console.log(os.cpus());
console.log(os.totalmem());
console.log(os.homedir());

/**
 * The path module provide utilites for working with file and directory paths.
 */
var path = require('path');

var pathUrl = path.join('/foo', 'bar', 'baz/asdf', 'quux', '..');
console.log(pathUrl);
console.log(path.basename('c:/a/b/c/d/text.txt'));
console.log(path.dirname('c:/a/b/c/d/text.txt'));
console.log(path.extname('c:/a/b/c/d/text.txt'));
console.log(path.parse('c:/a/b/c/d/text.txt'));
