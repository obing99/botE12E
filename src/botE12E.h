#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
HTTPClient http;

void koneksiWifi(String NAMA ,String PSWD){
  WiFi.mode(WIFI_STA);
  WiFi.begin(NAMA, PSWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

String bacaPesan(String botTOKEN) {
 String myurl= "https://api.telegram.org/" + botTOKEN+" /getUpdates?offset=-1";
 http.begin(myurl,"BB:DC:45:2A:07:E3:4A:71:33:40:32:DA:BE:81:F7:72:6F:4A:2B:6B");
 http.GET();
 String hasil = http.getString();
 http.end();
 DynamicJsonDocument doc(1024);
 deserializeJson(doc, hasil);
 String isiPesan = doc["result"][0]["message"]["text"]; 
 return isiPesan;
}

void kirimPesan(String Pesan, String botTOKEN, String ID){
 String url = "https://api.telegram.org/" + botTOKEN + "/sendMessage?chat_id=" + ID + "&text=" + Pesan;
 http.begin(url,"BB:DC:45:2A:07:E3:4A:71:33:40:32:DA:BE:81:F7:72:6F:4A:2B:6B");
 http.GET();
 http.end();
}
