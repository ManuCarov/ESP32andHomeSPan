#include "HomeSpan.h"
#include "VENTILADOR.h"

void setup(){
  Serial.begin(115200);

  homeSpan.setPairingCode("11122333");
  homeSpan.begin(Category::Switches, "Mi Ventilador");

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new VENTILADOR(14);
}

void loop(){
  homeSpan.poll();
}
