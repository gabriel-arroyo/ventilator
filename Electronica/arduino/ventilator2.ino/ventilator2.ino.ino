//Constantes del sistema

//-----estas variables pueden ser controladas con un display o potenciómetros-----
const int distancia = 3; //[cm]
const int tiempoEspera = 1000; //[ms]
const int velocidad = 1.5; //[cm/s]
const int cmPorRev=0.8;
const int pasosPorRev=1600;

const int dirPin = 3;
const int stepPin = 4;
const int enPin = 5;

void setup() {

  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  
  digitalWrite(enPin,LOW);
}

void loop() {
  
  digitalWrite(dirPin,HIGH); //Dirección inicial
  // 200 pasos por vuelta, 1600 micropasos por vuelta
  const int pasos = distancia*pasosPorRev/cmPorRev;
  const int tiempoEntrePasos=(velocidad*1000000)/(cmPorRev*pasosPorRev*2);
  
  for(int x=0; x<pasos; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(tiempoEspera);

  // Cambio de dirección
  digitalWrite(dirPin,LOW);
}
