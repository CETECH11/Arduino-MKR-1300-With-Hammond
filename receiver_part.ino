#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include<String.h>
rgb_lcd lcd;
int colorR = 0;
int colorG = 0;
int colorB = 255;
int data1;
int data2;
int data3;
int data4;
int data5;
int buzzer = 5;
String str;
char cstr[100];
String message = "";
unsigned int mlength; // message length 
char LoRaData;
void setup() {
lcd.begin(16, 2);
pinMode(buzzer,OUTPUT);
lcd.setRGB(colorR, colorG, colorB);
LoRa.begin(915E6);
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() 
{
String str1="",str2="",str3="",str4="",str5="";
int packetSize = LoRa.parsePacket(),i=0,len;
if (packetSize) 
{
  while (LoRa.available()) 
  {
  colorR = 0;
  colorG = 255;
  colorB = 0;
  lcd.setRGB(colorR, colorG, colorB);
    str1=str1+((char)LoRa.read());
   
    }
    len=str1.length();
    if(len-10 > 0)
    {
      str1=str1.substring(0,len);      
      str2=str1.substring(0,6);
      str3 =str1.substring(6,12);
      str4 = str1.substring(12,17);
      str5 = str1.substring(18,24);
      
      data1 = str2.toInt();
      data2 = str3.toInt();
      data3 = str4.toInt();
      data4 = str5.toInt();
    }
     Serial.print("HUM:");
     Serial.print(data1);
     Serial.println();

     Serial.print("Temp:");
     Serial.print(data2);
     Serial.println();

     
     Serial.print("light:");
     Serial.print(data3);
     Serial.println();

     Serial.print("AXIS:");
     Serial.print(data4);
     Serial.println();


     lcd.setCursor(0, 0);
     lcd.print("Temp:");
     lcd.print(data2);

     lcd.setCursor(8, 0);
     lcd.print("Hum:");
     lcd.print(data1);

     Serial.print("RSSI:");
     Serial.print(LoRa.packetRssi());
     Serial.println();


//     lcd.setCursor(0, 1);
//     lcd.print("RSSI:");
//     lcd.print(LoRa.packetRssi());
//
//     lcd.setCursor(8, 1);
//     lcd.print("axis:");
//     lcd.print(data4);
     
message = String(data1) +String(",") + String(data2) +String(",")+ String(data3) +String(",") + String(data4) +String(",");
 // message = message+ h +"," + t+","+ light_data +","+ gx +",";
delay(1000);
mlength = (sizeof(message)*4);
str = message;  
//Serial.print("length:");
//Serial.print(mlength);
//Serial.println();
//str.toCharArray(cstr,mlength);
//Serial1.println(cstr);
Serial.println(str);
Serial1.print(str);
if(data2 >= 30)
{
  Serial.println("high temperature");
  digitalWrite(buzzer,HIGH);
 int colorR = 255;
int colorG = 0;
int colorB = 0;
  lcd.setRGB(colorR, colorG, colorB);
     lcd.setCursor(0, 1);
     lcd.print("High Temperature");
    
}
else
{
   digitalWrite(buzzer,LOW);
 int colorR = 0;
int colorG = 255;
int colorB = 0;
  lcd.setRGB(colorR, colorG, colorB); 
  lcd.setRGB(colorR, colorG, colorB);
     lcd.setCursor(0, 1);
     lcd.print("                ");
}

if(data4 >=800 || data4 <0)
{
  digitalWrite(buzzer,HIGH);
  delay(250);
  digitalWrite(buzzer,LOW);
   delay(250);
   digitalWrite(buzzer,HIGH);
  delay(250);
  digitalWrite(buzzer,LOW);
}
 
   }}