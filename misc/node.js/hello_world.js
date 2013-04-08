
var $ = 1;
console.log($);
ret = console.log("Hello World")
console.log("Return of 'console.log':" + ret)

var i = {1:2,3:3}; 
console.log(i)
for (var i = 0; i < 3; i++)
	console.log(i);
console.log(i);
/*	
var net = require("net");
var reqstr = "GET / HTTP/1.1\r\n"+
  			 "HOST:200.200.0.17\r\n"+
			 "\r\n";
console.log("["+reqstr+"]");
var client = net.connect(
	{port: 80, 
	host: "200.200.0.17"},
    function() { //'connect' listener
  		console.log('EVENT: Client connected');
  
		});
console.log("en........");
client.write(reqstr);

client.on('data', function(data) {
  console.log(data.toString());
  client.end();
});
*/