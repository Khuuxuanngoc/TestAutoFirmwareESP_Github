// Copilot

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266httpUpdate.h>

const char* ssid = "Hshop.vn";
const char* password = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");

  t_httpUpdate_return ret = ESPhttpUpdate.update("https://raw.githubusercontent.com/Khuuxuanngoc/TestAutoFirmwareESP_Github/main/examples/Prototype_CheckFW_VerThenUpdate/firmware/esp.bin");

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("Update failed (%d): %s", 
                    ESPhttpUpdate.getLastError(), 
                    ESPhttpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("No updates available.");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("Update complete.");
      break;
  }
}

void loop() {
  // leave empty
}
