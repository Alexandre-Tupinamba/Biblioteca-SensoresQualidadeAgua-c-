/**********************************************************************************/
/* Thermistor -- manages a 10k Thermistor in the follwing circuit: 				  */
/*     																			  */
/*		(Ground) ---- (10k-Resister) -------|------- (Thermistor) ---- (+5v)	  */
/*                                          |									  */
/*                                      Analog Pin								  */
/*																				  */
/*			code based from code on Arduino playground found here:				  */
/*			http://www.arduino.cc/playground/ComponentLib/Thermistor2			  */
/*																				  */
/*								max mayfield									  */
/*								mm systems										  */
/*								max.mayfield@hotmail.com						  */
/**********************************************************************************/

#ifndef temperatura_h
#define temperatura_h

#include "Arduino.h"
#include "math.h"


class temperatura {
	public:
		temperatura(int pin);
		double PegaValorTemp();
	private:
		int _pin;
};

#endif
