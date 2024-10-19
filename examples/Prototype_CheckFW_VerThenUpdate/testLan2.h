#define ESP8266 // Hoặc ESP32

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <ESP8266httpUpdate.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <HTTPClient.h>
  #include <HTTPUpdate.h>
#else
  #error "Bạn cần định nghĩa ESP8266 hoặc ESP32"
#endif

const char* ssid = "Hshop.vn";
const char* password = "";

WiFiClient client;

void updateFirmware();

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  client.setTimeout(12000); // Tăng thời gian timeout
  Serial.println("WiFi connected");
}

const char* firmwareVersionURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.log";

String getFirmwareVersion() {
  HTTPClient http;
  Serial.println("Firmware URL: " + String(firmwareVersionURL));
  http.begin(client, String(firmwareVersionURL));
  int httpCode = http.GET();

  Serial.println("HTTP Code: " + String(httpCode)); // In mã trạng thái HTTP
  if (httpCode > 0) {
    Serial.println("Firmware version retrieved successfully.");
    return http.getString();
  } else {
    Serial.println("HTTP GET failed, error: " + http.errorToString(httpCode));
    return "ERROR";
  }
}

String currentVersion = "1.0.0"; // Phiên bản hiện tại của firmware

void loop() {
  String latestVersion = getFirmwareVersion();
  if (latestVersion != currentVersion) {
    Serial.println("latestVersion:" + latestVersion);
    Serial.println("currentVersion:" + currentVersion);
    updateFirmware();
  } else {
    Serial.println("No new firmware version detected.");
  }
  delay(3600000); // Kiểm tra mỗi giờ
}

const char* firmwareBinURL = "https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.bin";

void updateFirmware() {
  #if defined(ESP8266)
    Serial.println("Attempting to update firmware...");
    t_httpUpdate_return ret = ESPhttpUpdate.update(client, firmwareBinURL);
  #elif defined(ESP32)
    t_httpUpdate_return ret = httpUpdate.update(firmwareBinURL);
  #endif

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.println("Update failed: " + String(ESPhttpUpdate.getLastErrorString()));
      break;
    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("No updates available.");
      break;
    case HTTP_UPDATE_OK:
      Serial.println("Update successful.");
      break;
  }
}

void logUpdateResult(String message) {
  // Đoạn mã để ghi vào esp.log hoặc nơi khác
  Serial.println(message);
}
