/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Turbidez.h"

Turbidez::Turbidez(int pin)
{
  _pin = pin;
}

float Turbidez::pegaValorTurbidezNTU()
{
  analogEntrada = analogRead(_pin);
  tensao = (analogEntrada * 5.0) / 1024.0;
  valorNTU = -(1120.4*tensao*tensao)+(5742.3*tensao)-4353.8;
  return valorNTU;  
}

float Turbidez::pegaValorTurbidezMedia(){
    contagem = 0;
    somador = 0;
    while(contagem < 30){
       somador+=pegaValorTurbidezNTU();
       contagem++;
    }
    valorNTU = somador / 30;
  return valorNTU;
}

float Turbidez::pegaValorVoltagem(){

    analogEntrada = analogRead(_pin);
    tensao = (analogEntrada * 5.0) / 1024.0;
    return tensao;
}

