const int PIR = 4;

const int LED = 3;

int ESTADO = 0;    

void setup(){

  pinMode(PIR, INPUT); 

  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  delay(3000);

}

void loop(){

  ESTADO = digitalRead(PIR); 

  if (ESTADO == HIGH){

    digitalWrite(LED, HIGH);
    Serial.println("Deteccion de movimiento");

    delay(3000);

  } else {

    digitalWrite(LED, LOW);
    
  }

}
