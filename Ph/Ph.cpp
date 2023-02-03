/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Ph.h"

Ph::Ph(int pin)
{
  _pin = pin;
}

float Ph::pegaValorPh()
{
  analogEntrada = analogRead(_pin);
  tensao = (analogEntrada * 5.0) / 1024.0;
  valorPh = -5.70 * tensao + valorCalibracao;
  return valorPh;  
}

float Ph::pegaValorPhMedia(int n){
    contagem = 0;
    somador = 0;
    while(contagem < n){
       somador+=pegaValorPh();
       contagem++;
    }
    valorPh = somador / n;
  return valorPh;
}

void Ph::SomaOuSubtraiNaCalibracao(float n)
{
  valorCalibracao += n;
}

float Ph::pegaTensao()
{
  tensao = (analogEntrada * 5.0) / 1024.0;
  
  return tensao;  
}
