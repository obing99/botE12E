/* ===============================================
 * Cara Mudah akses Bot Telegram
 * 1. Jangan lupa instal library ArduinoJson 
 * 2. Jangan lupa Instal ESP8266 Board
 * ================================================*/
#include <botE12E.h>

String botTOKEN ="isi bot Token Telegram Anda" ;
String ID ="isi ID Telegram";

void setup(){
  koneksiWifi("SSID","PSWD");
}

void loop() {
  String pesan = bacaPesan(botTOKEN);
  kirimPesan("PESAN" , botTOKEN , ID);
}
