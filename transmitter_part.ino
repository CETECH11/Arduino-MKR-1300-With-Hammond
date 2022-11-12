#include <SPI.h>
#include <LoRa.h>
#include<String.h>
#include "DHT.h"
#define DUMP_REGS
#include <Wire.h>
#include "MPU6050.h"
#include <APDS9930.h>
#define DHTPIN 2 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
String str;
char cstr[500];
String message = "";
unsigned int mlength; // message length 
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;
float light_data;
float h;
float t;
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() 
{
  Serial.begin(9600);
  LoRa.begin(915E6);
  dht.begin();
  Wire.begin();
   accelgyro.initialize();
   if ( apds.init() )
   {
    Serial.println(F("APDS-9930 initialization complete"));
  } 
  else 
  {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }
  
  // Start running the APDS-9930 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  #ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for(reg = 0x00; reg <= 0x19; reg++) {
    if( (reg != 0x10) && \
        (reg != 0x11) )
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

  delay(500);
}

void loop() 
{
  while(1)
  {
     accelgyro.getRotation(&gx, &gy, &gz);
  light_details();
  temperature();
  message = String(h) +String(",") + String(t)+String(",")+ String(light_data)+String(",")+ String(gx)+String(",");
 // message = message+ h +"," + t+","+ light_data +","+ gx +",";

  delay(1000);
  mlength = (sizeof(message)*4);
  str = message;
  delay(100);
  LoRa.beginPacket();
  LoRa.print(str);
  delay(100);
  Serial.println(str);
  LoRa.endPacket(0);
  }
}

void light_details()
{
if (  !apds.readAmbientLightLux(ambient_light) ||
        !apds.readCh0Light(ch0) || 
        !apds.readCh1Light(ch1) ) {
    Serial.println(F("Error reading light values"));
  } 
  else {
    light_data = ambient_light;
  }  
}

void temperature()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); 

}