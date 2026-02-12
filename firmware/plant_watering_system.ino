// Librería para LCD
#include <LiquidCrystal.h>
// Librería para servo-motor
#include <Servo.h>

// Declarar LCD junto con pines a los que se conecta
const int RS = 12;
const int E = 11;
const int DB4 = 2;
const int DB5 = 3;
const int DB6 = 4;
const int DB7 = 5;
LiquidCrystal lcd(RS,E,DB4,DB5,DB6,DB7);

// Declarar servo-motor
Servo servo;

// Variable para el nivel de humedad
int humedad = 0;

// Configuración
// Constantes para los respectivos LED indicadores y los pines a los cuales están conectados
const int rojo = 10;
const int naranja = 9;
const int amarillo = 8;
const int verde = 7;
const int azul = 13;
// Constante para pin de señal de servo
const int servoPin = 6;
// Especificaciones del sistema
unsigned long tiempoSensor = 15; // Tiempo de inicialización y estabilización del sensor
unsigned long frecuenciaTono = 440; // Tono de bocina
unsigned long tiempoTonoComienzo = 1200;
unsigned long tiempoTonoFinal = 150;
unsigned long tiempoEntreTonos = 500;
unsigned long anguloApertura = 180; // Apertura máxima de servo que controla riego
unsigned long anguloCierre = 0;
unsigned long tiempoRiego = 5000;
unsigned long tiempoPostCiclo = 7000; // Tiempo antes de volver a evaluar humedad
/*Niveles de alerta
  LED rojo [nivelMin, nivel1)
  LED naranja [nivel1, nivel2)
  LED amarillo [nivel2, nivel3)
  LED verde [nivel3, nivel4)
  LED azul [nivel4, nivelMax]
  */
unsigned long nivelMin = 0;
unsigned long nivel1 = 1;
unsigned long nivel2 = 2;
unsigned long nivel3 = 3;
unsigned long nivel4 = 4;
unsigned long nivelMax = 5;


void setup(){
  // Inicialización de pines con LEDs
  pinMode(rojo, OUTPUT);
  pinMode(naranja, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  // Inicialización de pines conectados a sensor de humedad
  pinMode(A0, OUTPUT); // Pin de control de alimentación
  pinMode(A1, INPUT); // Pin de señal (lectura)
  // Inicialización de bocina
  pinMode(A5, OUTPUT);
  // Inicialización de LCD
  lcd.begin(16,2);
  lcd.print("Sistema de riego");
  lcd.setCursor(2,1);
  lcd.print("automatizado");
  // Inicialización de servo
  servo.attach(servoPin);
  servo.write(0);
  delay(2000);
}

void loop(){
  // Apaga los LEDs
  digitalWrite(rojo, LOW);
  digitalWrite(naranja, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
  
  humedad = lecturaSensor();
  int humedadMapeado = map(humedad,0,1024,nivelMin,nivelMax);
  mostrarNivel(humedadMapeado);
  evaluarHumedad(humedadMapeado);
  delay(tiempoPostCiclo); // Demora de visualización de indicadores
}

// Función de lectura del sensor
int lecturaSensor(){
  int lecturaHumedad = 0;
  digitalWrite(A0, HIGH); // Alimentación encendida
  delay(tiempoSensor);
  lecturaHumedad = analogRead(A1); // Captura
  digitalWrite(A0, LOW); // Alimentación interrumpida
  return lecturaHumedad;
}

// Función para imprimir nivel de humedad en LCD
void mostrarNivel(int nivelHumedad){
  lcd.clear();
  lcd.print("Nivel de humedad");
  lcd.setCursor(2,1);
  lcd.print(nivelHumedad);
}

// Función de riego
void regarMaceta(){
  lcd.clear();
  lcd.print("Tierra seca");
  lcd.setCursor(0,1);
  lcd.print("Regando...");
  servo.write(anguloApertura); // Habilitar riego
  delay(tiempoRiego); // En casos reales, el tiempo de riego dependerá del tamaño de la maceta
  servo.write(anguloCierre);
  lcd.clear();
  lcd.print("Riego terminado");
}

// Función para mostrar la lectura del nivel de humedad en los indicadores
void evaluarHumedad(int nivelHumedad){
  switch (nivelHumedad){
    case 0:
      // Habilitar el sistema de riego controlado por el servo en nivel crítico solamente
      digitalWrite(rojo, HIGH);
      tone(A5, frecuenciaTono, tiempoTonoComienzo); // Habilitar bocina
      regarMaceta();
      tone(A5, frecuenciaTono, tiempoTonoFinal);
      delay(tiempoEntreTonos);
      tone(A5, frecuenciaTono, tiempoTonoFinal);
      break;
    case 1:
      digitalWrite(naranja, HIGH);
      break;
    case 2:
      digitalWrite(amarillo, HIGH);
      break;
    case 3:
      digitalWrite(verde, HIGH);
      break;
    case 4:
      digitalWrite(azul, HIGH);
  }
}