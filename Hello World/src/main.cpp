#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial){}
  Serial.println("Hello World");
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print('-');
  vTaskDelay(1000);
  Serial.print('@');
  vTaskDelay(2000);
}