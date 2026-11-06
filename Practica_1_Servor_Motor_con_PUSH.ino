#include <Servo.h>

Servo MiServo;
const int PinPush = 2;
const int PinServo = 9;

int EstadoServo = 0;
int UltimoEstadoPush = HIGH;

void setup() {
  MiServo.attach(PinServo);
  pinMode(PinPush,INPUT_PULLUP);
  MiServo.write(0);
}

void loop() {
  int EstadoPush = digitalRead(PinPush);
  if( EstadoPush == LOW && UltimoEstadoPush == HIGH){
    EstadoServo = !EstadoServo;

    if( EstadoServo == 1){
      MiServo.write(90);
    }else{
      MiServo.write(0);
    }
      delay(200);
  }
  UltimoEstadoPush = EstadoPush;
}