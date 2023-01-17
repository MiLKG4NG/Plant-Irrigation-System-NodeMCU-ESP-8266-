
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLe4f7fJUv"
#define BLYNK_DEVICE_NAME "Plant Irrigation System"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

const int sensor_pin = A0;
double moisture_percentage;

/* BLYNK_WRITE(V0)
{
  if(param.asInt()==0){
  digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);
  }
} */

BLYNK_CONNECTED(){
  Blynk.syncAll();
  Blynk.virtualWrite(V1, moisture_percentage);
}
void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );

  Serial.print("\nSoil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  delay(1000);
  
  if (moisture_percentage >= 20) {
  digitalWrite(D4, true);
  delay(1000);
  digitalWrite(D4, false);
  delay(1000);
  }else{
    digitalWrite(D4, false);
  }
  
  BlynkEdgent.run();
}

