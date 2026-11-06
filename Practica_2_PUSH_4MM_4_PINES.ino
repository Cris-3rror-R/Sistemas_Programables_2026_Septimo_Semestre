const int PinBtn = 7;
const int PinLed = 13;

bool estadoLed = false;       
int ultimoEstadoBoton = HIGH; 

void setup() {
  Serial.begin(9600);
  
  pinMode(PinBtn , INPUT_PULLUP);
  pinMode(PinLed , OUTPUT);
  
  digitalWrite(PinLed , LOW);

}

void loop() {
  int estadoBotonActual = digitalRead(PinBtn );

  if (ultimoEstadoBoton == HIGH && estadoBotonActual == LOW) {
    estadoLed = !estadoLed;
    
    digitalWrite(PinLed , estadoLed ? HIGH : LOW);
    
  }
  ultimoEstadoBoton = estadoBotonActual;
}

