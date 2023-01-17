
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

//const int sensor_pin = A0;
int moisture_percentage;

// Blynk LED Writing
BLYNK_WRITE(V0)
{
  if(param.asInt()==0){
  digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);
  }
}

// Cloud Connection
BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0);
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
  moisture_percentage = ( 100.00 - ( (analogRead(A0)/1023.00) * 100.00 ) );
  BlynkEdgent.run();
}

