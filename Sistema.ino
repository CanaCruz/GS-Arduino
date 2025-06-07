#include <LiquidCrystal.h>

// LCD nos pinos digitais
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Variáveis
long duracao;
float distancia_cm;
int percentual;
int pico = 0;  // maior nível atingido
const int profundidade_max = 400; // profundidade do reservatório em cm

// Pinos
const int pino_trigger = 8;
const int pino_echo = 9;
const int led_verde = 10;
const int led_amarelo = 11;
const int led_laranja = A0; 
const int led_vermelho = 12;
const int buzzer = A1;

void setup() {
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_echo, INPUT);

  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_laranja, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Inicializando...");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Medição do sensor ultrassônico
  digitalWrite(pino_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);

  duracao = pulseIn(pino_echo, HIGH);
  distancia_cm = duracao * 0.034 / 2.0;

  // Cálculo da porcentagem
  percentual = (profundidade_max - distancia_cm) * 100 / profundidade_max;
  if (percentual < 0) percentual = 0;
  if (percentual > 100) percentual = 100;

  // Atualiza pico
  if (percentual > pico) {
    pico = percentual;
  }

  // Alternância de telas no LCD
  unsigned long tempo = millis();
  int tela = (tempo / 3000) % 2;

  lcd.setCursor(0, 0);
  if (tela == 0) {
    lcd.print("Nivel atual:     ");
    lcd.setCursor(0, 1);
    lcd.print(percentual);
    lcd.print("%             ");
  } else {
    lcd.print("Pico maximo:     ");
    lcd.setCursor(0, 1);
    lcd.print(pico);
    lcd.print("%             ");
  }

  // Controle de LEDs e buzzer
  if (percentual >= 90) {
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_laranja, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, LOW);
    tone(buzzer, 1000, 300); // alerta sonoro breve
  }
  else if (percentual >= 81) {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_laranja, HIGH);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, LOW);
    noTone(buzzer);
  }
  else if (percentual >= 61) {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_laranja, LOW);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, LOW);
    noTone(buzzer);
  }
  else {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_laranja, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, HIGH);
    noTone(buzzer);
  }

  delay(500);
}
