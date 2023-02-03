#include <temperatura.h>

temperatura temp(A0); // Variavél tipo thermistor recebe a porta 0 analógica como parametro

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temperatura = temp.PegaValorTemp(); //Função para pegar a temperatura
  Serial.print("Temperatura no Sensor e: ");
  Serial.print(temperatura);//Print temperatura
  Serial.println("*C");
  delay(1000);
}
