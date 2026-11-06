int LadoX = A1;
int LadoY = A0;

int LedArriba = 3;
int LedAbajo = 4;
int LedDerecha = 6;
int LedIzquierda = 5;
int LedCentro = 7;
int JoyBtn = 2; 

int EstadoBtn = LOW;

int ValorX;
int ValorY;

void setup() {
  Serial.begin(9600);

  pinMode(LedArriba, OUTPUT);
  pinMode(LedDerecha, OUTPUT);
  pinMode(LedIzquierda, OUTPUT);
  pinMode(LedAbajo, OUTPUT);
  pinMode(LedCentro, OUTPUT);
  
  pinMode(JoyBtn, INPUT_PULLUP); 
}

void loop() {
  ValorX = analogRead(LadoX);
  ValorY = analogRead(LadoY);

  digitalWrite(LedCentro, HIGH);
  // Derecha 
  if (ValorX > 1000) {
    digitalWrite(LedDerecha, LOW);
    Serial.print("Derecha X = ");
    Serial.println(ValorX);
  } else {
    digitalWrite(LedDerecha, HIGH);
  }

  // Izquierda
  if (ValorX < 200) { 
    digitalWrite(LedIzquierda, LOW);
    Serial.print("Izquierda X = ");
    Serial.println(ValorX);
  } else {
    digitalWrite(LedIzquierda, HIGH);
  }

  // Arriba
  if (ValorY > 1000) { 
+    digitalWrite(LedArriba, LOW);
    Serial.print("Arriba Y = ");
    Serial.println(ValorY);
  } else {
    digitalWrite(LedArriba, HIGH);
  }

  // Abajo
  if (ValorY < 500) {
    digitalWrite(LedAbajo, LOW);
    Serial.print("Abajo Y = ");
    Serial.println(ValorY);
  } else {
    digitalWrite(LedAbajo, HIGH);
  }

  EstadoBtn = digitalRead(JoyBtn);
  if (EstadoBtn = HIGH){
      digitalWrite(LedArriba, LOW);
      digitalWrite(LedAbajo, LOW);
      digitalWrite(LedDerecha, LOW);
      digitalWrite(LedIzquierda, LOW);
      digitalWrite(LedCentro, LOW);
  }
  delay(50);
}
