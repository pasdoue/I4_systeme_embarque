#include <Max3421e.h>
#include <Usb.h>
#include <AndroidAccessory.h>
#define GREEN_LED 12
#define RED_LED 3
AndroidAccessory acc("Manufacturer",
                "Model",
                "Description",
                "1.0",
                "http://yoursite.com",
                "0000000012345678");
void setup()
{
  // set communiation speed
  Serial.begin(115200);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  acc.powerOn();
}

void loop()
{
  byte msg[0];
  if (acc.isConnected()) {
    int len = acc.read(msg, sizeof(msg), 1); // read data into msg variable
    if (len > 0) {
      if (msg[0] == 1)
      {
        digitalWrite(GREEN_LED,HIGH); // turn on light
        digitalWrite(RED_LED,LOW);
      }
      else
      {
        digitalWrite(GREEN_LED,LOW); // turn off light
        digitalWrite(RED_LED,HIGH);
      }
    }
  }
  else
  {
    digitalWrite(RED_LED , LOW); // turn off light
    digitalWrite(GREEN_LED , LOW);
  }
}
