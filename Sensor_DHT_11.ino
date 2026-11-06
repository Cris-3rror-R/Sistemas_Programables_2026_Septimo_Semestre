#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

// Definimos el pin donde conectaremos el LED
#define LEDPIN 3 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando...");
  
  dht.begin();
  
  pinMode(LEDPIN, OUTPUT); 
  digitalWrite(LEDPIN, LOW); // Inicia apagado
}

void loop() {
  // El DHT11 necesita 2 segundos entre lecturas
  delay(2000);

  // Leemos la humedad y la temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  // --- FILTRO DE DESCONEXIÓN ---
  // Si no hay lectura válida (los cables se movieron), detenemos todo
  if (isnan(h) || isnan(t)) {
    digitalWrite(LEDPIN, LOW); // Apagamos el LED por seguridad si se pierde la señal
    return; // Este comando aborta el resto del código y vuelve a empezar el loop
  }

  //---------- Lógica del LED ----------
  
  // Si llegamos hasta aquí, es porque SÍ hay conexión perfecta
  if (t > 28.5) {
    digitalWrite(LEDPIN, HIGH); // Enciende
  } 
  else {
    digitalWrite(LEDPIN, LOW);  // Apaga
  }

  //---------- Enviamos las lecturas por el puerto serial ----------
  
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t"); 

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");
}