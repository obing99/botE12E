/* ===============================================
 * Cara Mudah akses Bot Telegram
 * 1. Jangan lupa instal library ArduinoJson 
 * 2. Jangan lupa Instal ESP8266 Board
 * 3. Jangan lupa instal library MFRC522
 * ================================================
 * NODEMCU E12-E => MFRC522
 * D4(GPIO2) => SDA (SS)
 * D5(GPIO14)=> SCK
 * D7(GPIO13)=> MOSI
 * D6(GPIO12)=> MISO(SCL)
 * GND => GND
 * D3(GPIO0) => RST (FLASH)
 * 3.3V => 3.3V
 * ================================================*/
#include <SPI.h>
#include <MFRC522.h>
#include <botE12E.h>

#define SS_PIN 2
#define RST_PIN 0
MFRC522 mfrc522(SS_PIN, RST_PIN);

String botTOKEN ="isi bot Token Telegram Anda" ;
String ID ="isi ID Telegram";

void setup(){
  SPI.begin(); 
  mfrc522.PCD_Init();
  koneksiWifi("SSID","PSWD");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()){return;}
  if ( ! mfrc522.PICC_ReadCardSerial()){return;}
  String content= ""; 
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     content.concat(String(mfrc522.uid.uidByte[i]));
  }
  String idRFID = content;
  kirimPesan(idRFID , botTOKEN , ID);
}
