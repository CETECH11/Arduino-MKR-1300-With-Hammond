#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<String.h>
#include <SoftwareSerial.h>//libraries needed in communicating with gps and nodemcu
int RXPin = D2;//tx pin of mkr1300 connected to this pin
int TXPin = D1;//rx pin of mkr1300 connected to this pin
SoftwareSerial data_serial(RXPin, TXPin);//declaring the rx,tx pins
int incomingByte = 0;

int data1;
int data2;
int data3;
int data4;
int data5;
String LoRaData;
String jsonBuffer;
float ta;// Temperature details 
float ha; // Humidity details
float rs; //Rssi details

char auth[] = "xxxxxxxxxxxxx";// Your blynk app token id
char ssid[] = "xxxxxxxxxxxx"; // your Wifi name
char pass[] = "xxxxxxxxxxxxxxx"; // your wifi password

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  data_serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
String str1="",str2="",str3="",str4="",str5="";
 int i=0,len;
char commandbuffer[400];
  if (data_serial.available())
  {
    delay(500);
while( data_serial.available() && i< 99) 
{
commandbuffer[i++] = data_serial.read();
}
//commandbuffer[i++]='\0';
  }
  Serial.println((char*)commandbuffer);
  str1=str1+((char*)commandbuffer);
  len=str1.length();
  Serial.println(len);
    if(len-15 > 0)
    {
      str1=str1.substring(0,len);      
      str2=str1.substring(0,2);
      str3 =str1.substring(3,5);
      str4 = str1.substring(6,8);
      str5 = str1.substring(9,15);
      data1 = str2.toInt();
      data2 = str3.toInt();
      data3 = str4.toInt();
      data4 = str5.toInt();
    }
     Serial.print("hum:");
     Serial.print(data1);
     Serial.println();

     Serial.print("temp:");
     Serial.print(data2);
     Serial.println();

     Serial.print("Light:");
     Serial.print(data3);
     Serial.println();

     Serial.print("axis:");
     Serial.print(data4);
     Serial.println();
     
      Blynk.virtualWrite(V0,data1);
      Blynk.virtualWrite(V1,data2);
      Blynk.virtualWrite(V2,data3);
      Blynk.virtualWrite(V3,data4);
  
      Blynk.run();
      timer.run();
      
}