#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WebServer.h>
#include "Wire.h"

// To be replaced with network credentials
const char* ssid = "admin";
const char* password = "123456789";
 LiquidCrystal_I2C lcd(0x27,16,2);
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int data1;
String data2; 
int data3;
String data4; 
void setup(void){
 
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D0, OUTPUT);
   lcd.begin();                    
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME        ");
  delay(2000);
  lcd.clear();
  
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    lcd.setCursor(0, 0);
  lcd.print("Connecting...           ");
  delay(1000);
  }

  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   lcd.setCursor(0, 0);
  lcd.print(WiFi.localIP());
  delay(5000);
  lcd.clear();
serial.read(Lat, Long)
  delay(2000);
  server.on("/", [](){
    page = "<!DOCTYPE html><html><head><title>Modern Security System with Anti-Theft Feature</title></head><body style=\"color:green;text-align:centre\"><h1>Modern Security System with Anti-Theft Feature</h1>";
    page+="<h3>BIKE Status:</h3><h4>"+String(data4)+"</h4><meta http-equiv=”refresh” content=”3\"/></body></html>";
    page+="<h5>Vibration Status:</h4><h6>"+String(data2)+"</h6><meta http-equiv=”refresh” content=”3\"/></body></html>";
    server.send(200, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  data1 = digitalRead(D6);
 data3 = digitalRead(D7);
  if(data1==0)
  {
    data2="Vibration Detected - Lat---- N  Long- ---- E";
    digitalWrite(D0,HIGH);
     lcd.setCursor(0, 0);
  lcd.print("VIBRATION        ");
  }
   else if(data1==1)
  {
    data2=" NORMAL ";
    digitalWrite(D0,LOW);
    lcd.setCursor(0, 0);
 lcd.print("NORMAL           ");
  }
  delay(1000);

  if(data3==0)
  {
    data4="Mishandling Detected - Lat----N  Long- ---- E  ";
    digitalWrite(D0,HIGH);
     lcd.setCursor(0, 0);
  lcd.print("MISHANDLE          ");
  }
   else if(data3==1)
  {
    data4=" NORMAL";
    digitalWrite(D0,LOW);
    lcd.setCursor(0, 0);
 lcd.print("NORMAL               ");
  }
  delay(1000);
  server.handleClient();
}