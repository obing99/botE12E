/* ===============================================
 * Cara Mudah akses Bot Telegram
 * 1. Jangan lupa instal library ArduinoJson 
 * 2. Jangan lupa Instal ESP8266 Board
 * 3. Ini contoh Sketch ON OFF lampu dari telegram
 *    Dan ada pesan notofikasi ke telegram anda
 * ================================================*/
#include <botE12E.h>

String botTOKEN ="isi bot Token Telegram Anda" ;
String ID ="isi ID Telegram";

void setup(){
  Serial.begin(9600);
  pinMode(16,OUTPUT);
  koneksiWifi("SSID","PSWD");
}

void loop() {
  String pesan = bacaPesan(botTOKEN);
  if (pesan=="ON") {
    digitalWrite(16,HIGH);
    kirimPesan("Lampu ON" , botTOKEN , ID);
  }

   if (pesan=="OFF") {
    digitalWrite(16,LOW);
    kirimPesan("Lampu OFF" , botTOKEN , ID);
  }
}
