#include "testLan3.h"

// // // #define ESP8266 // Hoặc ESP32

// // #if defined(ESP8266)
// //   #include <ESP8266WiFi.h>
// //   #include <ESP8266HTTPClient.h>
// //   #include <ESP8266httpUpdate.h>
// // #elif defined(ESP32)
// //   // #include <WiFi.h>
// //   // #include <HTTPClient.h>
// //   // #include <Update.h> // Thư viện Update cho ESP32

// //   #include <Update.h>
// //   #include <HTTPClient.h>
// //   #include <HTTPUpdate.h>
// // #else
// //   #error "Bạn cần định nghĩa ESP8266 hoặc ESP32"
// // #endif

// // const char* ssid = "Your_SSID";
// // const char* password = "Your_PASSWORD";

// // void setup() {
// //   Serial.begin(115200);
// //   WiFi.begin(ssid, password);

// //   while (WiFi.status() != WL_CONNECTED) {
// //     delay(500);
// //     Serial.print(".");
// //   }

// //   Serial.println("WiFi connected");
// // }

// // const char* firmwareVersionURL = "https://raw.githubusercontent.com/yourusername/yourrepo/main/esp.log";

// // String getFirmwareVersion() {
// //   HTTPClient http;
// //   http.begin(firmwareVersionURL);
// //   int httpCode = http.GET();

// //   if (httpCode > 0) {
// //     return http.getString();
// //   } else {
// //     return "ERROR";
// //   }
// // }

// // String currentVersion = "1.0.0"; // Phiên bản hiện tại của firmware

// // void loop() {
// //   String latestVersion = getFirmwareVersion();
// //   if (latestVersion != currentVersion) {
// //     updateFirmware();
// //   }
// //   delay(3600000); // Kiểm tra mỗi giờ
// // }

// // const char* firmwareBinURL = "https://raw.githubusercontent.com/yourusername/yourrepo/main/esp.bin";

// // void updateFirmware() {
// //   #if defined(ESP8266)
// //     // t_httpUpdate_return ret = ESPhttpUpdate.update(firmwareBinURL);
// //     // t_httpUpdate_return ret = ESPhttpUpdate.update(String(firmwareBinURL));
// //     t_httpUpdate_return ret = ESPhttpUpdate.update(WiFiClient(), firmwareBinURL); // Sửa thành WiFiClient()

// //   #elif defined(ESP32)
// //     t_httpUpdate_return ret = Update.begin(UPDATE_SIZE_UNKNOWN) ? Update.writeStream(httpUpdateStream) : HTTP_UPDATE_FAILED;
// //     if (ret == HTTP_UPDATE_OK && !Update.end()) {
// //       ret = HTTP_UPDATE_FAILED;
// //     }
// //   #endif

// //   switch (ret) {
// //     case HTTP_UPDATE_FAILED:
// //       Serial.println("Update failed.");
// //       break;
// //     case HTTP_UPDATE_NO_UPDATES:
// //       Serial.println("No updates available.");
// //       break;
// //     case HTTP_UPDATE_OK:
// //       Serial.println("Update successful.");
// //       break;
// //   }
// // }

// // void logUpdateResult(String message) {
// //   // Đoạn mã để ghi vào esp.log hoặc nơi khác
// //   Serial.println(message);
// // }


// // #define ESP8266 // Hoặc ESP32

// #if defined(ESP8266)
//   #include <ESP8266WiFi.h>
//   #include <ESP8266HTTPClient.h>
//   #include <ESP8266httpUpdate.h>
// #elif defined(ESP32)
//   #include <WiFi.h>
//   #include <HTTPClient.h>
//   #include <HTTPUpdate.h>
// #else
//   #error "Bạn cần định nghĩa ESP8266 hoặc ESP32"
// #endif

// const char* ssid = "Hshop.vn";
// const char* password = "";

// WiFiClient client; // Khai báo WiFiClient ở đây

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   // Set a longer timeout for the client
//   client.setTimeout(12000); // 12 seconds
//   Serial.println("WiFi connected");
// }

// // const char* firmwareVersionURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/blob/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.log";
// // const char* firmwareVersionURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/refs/heads/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.log";
// const char* firmwareVersionURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.log";

// // String getFirmwareVersion() {
// //   HTTPClient http;
// //   http.begin(client, firmwareVersionURL); // Sử dụng client ở đây
// //   int httpCode = http.GET();

// //   if (httpCode > 0) {
// //     return http.getString();
// //   } else {
// //     return "ERROR";
// //   }
// // }

// // String getFirmwareVersion() {
// //   HTTPClient http;
// //   http.begin(client, firmwareVersionURL); // Sử dụng client
// //   int httpCode = http.GET();

// //   if (httpCode > 0) {
// //     Serial.println("HTTP Code: " + String(httpCode)); // In mã trạng thái HTTP
// //     return http.getString();
// //   } else {
// //     Serial.println("HTTP GET failed, error: " + String(http.errorToString(httpCode)));
// //     return "ERROR";
// //   }
// // }

// // String getFirmwareVersion() {
// //   HTTPClient http;
// //   Serial.println("Firmware URL: " + String(firmwareVersionURL));
// //   http.begin(client, firmwareVersionURL); // Sử dụng client
// //   int httpCode = http.GET();

// //   if (httpCode > 0) {
// //     Serial.println("HTTP Code: " + String(httpCode)); // In mã trạng thái HTTP
// //     return http.getString();
// //   } else {
// //     Serial.println("HTTP GET failed, error: " + String(http.errorToString(httpCode)));
// //     return "ERROR";
// //   }
// // }

// String getFirmwareVersion() {
//   HTTPClient http;
//   Serial.println("Firmware URL: " + String(firmwareVersionURL));
//   http.begin(client, firmwareVersionURL);
//   int httpCode = http.GET();

//   Serial.println("HTTP Code: " + String(httpCode)); // In mã trạng thái HTTP
//   if (httpCode == HTTP_CODE_OK) {
//     return http.getString();
//   } else {
//     Serial.println("HTTP GET failed, error: " + http.errorToString(httpCode));
//     return "ERROR";
//   }
// }


// String currentVersion = "1.0.0"; // Phiên bản hiện tại của firmware

// void loop() {
//   String latestVersion = getFirmwareVersion();
//   if (latestVersion != currentVersion) {
//     Serial.println("latestVersion:" + latestVersion);
//     Serial.println("currentVersion:" + currentVersion);
//     updateFirmware();
//   }
//   delay(3600000); // Kiểm tra mỗi giờ
// }

// const char* firmwareBinURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/refs/heads/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.bin";


// void updateFirmware() {
//   #if defined(ESP8266)
//     t_httpUpdate_return ret = ESPhttpUpdate.update(client, firmwareBinURL); // Sử dụng client ở đây
//   #elif defined(ESP32)
//     t_httpUpdate_return ret = httpUpdate.update(firmwareBinURL);
//   #endif

//   switch (ret) {
//     case HTTP_UPDATE_FAILED:
//       Serial.println("Update failed.");
//       break;
//     case HTTP_UPDATE_NO_UPDATES:
//       Serial.println("No updates available.");
//       break;
//     case HTTP_UPDATE_OK:
//       Serial.println("Update successful.");
//       break;
//   }
// }

// void logUpdateResult(String message) {
//   // Đoạn mã để ghi vào esp.log hoặc nơi khác
//   Serial.println(message);
// }
