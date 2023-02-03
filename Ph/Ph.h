/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Ph_h
#define Ph_h

#include "Arduino.h"

class Ph
{
  public:
    Ph(int pin);
    float pegaValorPh();
    void SomaOuSubtraiNaCalibracao(float n);
    float pegaValorPhMedia(int n);//maior precisão, recomendado
    float pegaTensao();
  private:
    int _pin;
    float valorCalibracao = 21.34; // 21.34 valor padrão
    int analogEntrada; // PinoAnalogEntrada
    float tensao; // Depois de fazer a conversão para voltagem
    float valorPh;//Placeholder para return
    int contagem;//Cauculo media
    float somador;//Acumulador
};

#endif

