#include <Ph.h>

Ph ph(A0);  // instância um objeto chamado "ph" e passa como parâmetro a porta analógica

void setup()
{
  Serial.begin(9600);//Defini a taxa de atualização do serial
}
int n = 13; // quantas leituras
void loop()
{
  float valor; // Placeholder para o return do método
  valor = ph.pegaValorPhMedia(n);// Funcao para pegar o valor do ph, coleta n vezes
 
  Serial.print("valor ph ");
  Serial.println(valor);
  delay(2000);
}
