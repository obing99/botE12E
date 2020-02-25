#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
const uint8_t fingerprint[20] = {0xbb, 0xdc, 0x45, 0x2a, 0x07, 0xe3,0x4a, 0x71, 0x33, 0x40, 0x32, 0xda, 0xbe, 0x81, 0xf7, 0x72, 0x6f, 0x4a, 0x2b, 0x6b};
ESP8266WiFiMulti WiFiMulti;
HTTPClient https;

void koneksiWifi(const char* NAMA ,const char* PSWD){
 WiFi.mode(WIFI_STA);
 WiFiMulti.addAP(NAMA , PSWD);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
  }
}

String bacaPesan(String botTOKEN) {
 std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
 client->setFingerprint(fingerprint);
 String myurl = "https://api.telegram.org/" + botTOKEN + "/getUpdates?offset=-1";
 https.begin(*client , myurl);
 https.GET();
 String hasil = https.getString();
 https.end();
 DynamicJsonDocument doc(1024);
 deserializeJson(doc, hasil);
 String isiPesan = doc["result"][0]["message"]["text"]; 
 return isiPesan;
}

void kirimPesan(String Pesan, String botTOKEN, String ID){
 std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
 client->setFingerprint(fingerprint);
 String url = "https://api.telegram.org/" + botTOKEN + "/sendMessage?chat_id=" + ID + "&text=" + Pesan;
 https.begin(*client , url);
 https.GET();
 https.end();
}
