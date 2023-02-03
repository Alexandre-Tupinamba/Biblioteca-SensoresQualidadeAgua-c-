#include <Turbidez.h>

Turbidez turbidez(A0);

void setup() 
{
  Serial.begin(9600);

  
} 
void loop() 
{
  float valor = turbidez.pegaValorTurbidezMedia();
  float voltagem = turbidez.pegaValorVoltagem();
  Serial.println(valor);
  Serial.println(voltagem);
  
  delay(1000);
} 
