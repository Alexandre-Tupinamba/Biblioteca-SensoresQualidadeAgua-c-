/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Turbidez_h
#define Turbidez_h

#include "Arduino.h"

class Turbidez
{
  public:
    Turbidez(int pin);
    float pegaValorTurbidezNTU();
    float pegaValorTurbidezMedia();//maior precisão, recomendado
    float pegaValorVoltagem();
  private:
    int _pin;
    int analogEntrada; // PinoAnalogEntrada
    float tensao; // Depois de fazer a conversão para voltagem
    float valorNTU;//Placeholder para return
    int contagem;//Cauculo media
    float somador;//Acumulador
};

#endif

