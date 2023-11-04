struct VENTILADOR : Service::Switch{
  
  int ventiladorPin;
  SpanCharacteristic *power;

  VENTILADOR(int ventiladorPin) : Service::Switch(){
    power = new Characteristic::On();
    this->ventiladorPin = ventiladorPin;
    pinMode(ventiladorPin, OUTPUT);
  }

  boolean update(){
    digitalWrite(ventiladorPin, power->getNewVal());
    return(true);
  }
};
