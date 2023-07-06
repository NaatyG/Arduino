// Projeto Arduino
// Ler a temperatura do sensor TPM36
// Se a temperatura for igual ou maior que 30 graus, acionar o motor CC
// Caso a temperatura seja maior que 50 graus, acionar o LED vermelho e o buzzer

// Bibliotecas
#include <Arduino.h>

// Definir os pinos
#define LED 13
#define BUZZER 7
#define SENSOR A0

// Variáveis
int temperatura = 0;

void setup()
{
    // Inicializar o monitor serial
    Serial.begin(9600);

    // Definir os pinos como saída
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop()
{
    // Ler a temperatura
    temperatura = analogRead(SENSOR);

    // Converter a temperatura para graus Celsius
    temperatura = map(temperatura, 0, 1023, 0, 500);
    temperatura = temperatura / 10;

    // Imprimir a temperatura no monitor serial
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" graus Celsius");

    // Se a temperatura for maior ou igual a 30 graus, acionar o motor piezo
    if (temperatura >= 30)
    {
        digitalWrite(BUZZER, HIGH);
    }
    else
    {
        digitalWrite(BUZZER, LOW);
    }

    // Se a temperatura for maior que 50 graus, acionar o LED e o buzzer
    if (temperatura > 50)
    {
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }

    // Aguardar 1 segundo
    delay(1000);
}
