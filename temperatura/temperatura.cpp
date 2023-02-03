/**************************************************************/
/*				max mayfield								  */
/*				mm systems									  */
/*				max.mayfield@hotmail.com					  */
/*															  */
/*	code based from code on Arduino playground found here:	  */
/*	http://www.arduino.cc/playground/ComponentLib/Thermistor2 */
/**************************************************************/

/* ======================================================== */

#include "Arduino.h"
#include "temperatura.h"

//--------------------------
temperatura::temperatura(int pin) {
  _pin = pin;
}

//--------------------------
double temperatura::PegaValorTemp() {
  // Lê o valor analógico de entrada
  int RawADC = analogRead(_pin);

  long Resistencia;
  double Temp;

  // Usando um resistor de 10k podemos calcular: Resistencia = (1024/ADC)
  Resistencia=((10240000/RawADC) - 10000);

  /******************************************************************/
  /* Utiliza a equação da temperatura do Steinhart-Hart:				*/
  /*    Temperatura em Kelvin = 1 / {A + B[ln(R)] + C[ln(R)]^3}		*/
  /*    onde A = 0.001129148, B = 0.000234125 and C = 8.76741E-08	*/
  /******************************************************************/
  Temp = log(Resistencia);
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;  // Converte Kelvin para Celsius

  /* - OUTPUT TESTE - Remova o comentário para printar os valores no monitor serial
  Serial.print("ADC: "); Serial.print(RawADC); Serial.print("/1024");  // Print valor analogico de entrada
  Serial.print(", Volts: "); printDouble(((RawADC*4.860)/1024.0),3);   // Print voltagem.
  Serial.print(", Resistencia: "); Serial.print(Resistencia); Serial.print("ohms");
  */

  // Descomente a linha a seguir para retornar a temperatura em Fahrenheit
  //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Conversão para Fahrenheit

  return Temp;  // Retorna temperatura
}

/* ======================================================== */
