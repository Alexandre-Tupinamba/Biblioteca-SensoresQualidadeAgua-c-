#include "SensoresUnificados.h"

void setup()
{
    Serial.begin(9600);
    gravityTds.begin();  //inicialização
  }

void loop()
{
    lerValorTemp();  //Lê valor temperatura e armazena na variavel global "temperatura";
    printTemp();

    lerValorTDS();  
    printTDS();

    lerValorPh();
    printPh();

    lerValorTurbidez();
    printTurbidez();

    
    delay(1000);
}
