// https://hocarm.org/tao-server-ota-cap-nhat-firmware-cho-esp8266/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
const char* ssid = "Hshop.vn";
const char* password = "";
const char *currentVersion = "1.0";
// const char *serverUrl = "http://192.168.1.150:3000/firmware.bin";
const char *serverUrl = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.bin";
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("ESP8266 http update, current version: ");
  Serial.println(currentVersion);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  t_httpUpdate_return ret = ESPhttpUpdate.update(serverUrl, currentVersion);
  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(),
                    ESPhttpUpdate.getLastErrorString().c_str());
      break;
    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;
    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
  }
}
void loop() {
}

// nodejs Code

// var fs = require('fs');
// var url = require('url');
// var http = require('http');
// var querystring = require('querystring');
// var crypto = require('crypto');
// // function gửi yêu cầu(response) từ phía server hoặc nhận yêu cầu (request) của client gửi lên
// function requestHandler(request, response) {
//     // Giả sử địa chỉ yêu cầu firmware http://192.168.1.7:8000/firmware.bin
//     var uriData = url.parse(request.url);
//     var pathname = uriData.pathname; // /firmware.bin
//     if (pathname == '/firmware.bin') {
//         var ver = request.headers['x-esp8266-version'];
//         console.log('Client request update, version ', ver);
//         if (ver == '1.0') {
//             console.log('Send firmware 2.0 to client');
//             fs.readFile('./esp8266-firmware-2.0.bin', function(error, content) {
//                 response.writeHead(200, {
//                     'Content-Type': 'binary/octet-stream',
//                     'Content-Length': Buffer.byteLength(content),
//                     'x-MD5': crypto.createHash('md5').update(content).digest("hex")
//                 });
//                 response.end(content);
//             });
//         } else {
//             response.statusCode = 304;
//             response.end();
//         }
//     }
// }
// var server = http.createServer(requestHandler);
// server.listen(3000);
// console.log('Server listening on port 3000');

// run command
// nodemon server.js