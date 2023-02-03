/***************************************************
 DFRobot Gravity: Analog TDS Sensor/Meter
 <https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_TDS_Sensor_/_Meter_For_Arduino_SKU:_SEN0244>

 ***************************************************
 This sample code shows how to read the tds value and calibrate it with the standard buffer solution.
 707ppm(1413us/cm)@25^c standard buffer solution is recommended.

 Created 2018-1-3
 By Jason <jason.ling@dfrobot.com@dfrobot.com>

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution.
 ****************************************************/

 /***********Notice and Trouble shooting***************
 1. This code is tested on Arduino Uno with Arduino IDE 1.0.5 r2 and 1.8.2.
 2. Calibration CMD:
     enter -> enter the calibration mode
     cal:tds value -> calibrate with the known tds value(25^c). e.g.cal:707
     exit -> save the parameters and exit the calibration mode
 ****************************************************/

#include <EEPROM.h>
#include <temperatura.h>
#include "GravityTDS.h"
#include <Turbidez.h>
#include <Ph.h>
GravityTDS gravityTds(A0);
temperatura temp(A1);
Turbidez turbidez(A2);
Ph ph(A3);

float _temperatura = 25,_tdsValue = 0, _ph = 0, _turbidez = 0;

void lerValorTemp(){
  _temperatura = temp.PegaValorTemp();
}

void printTemp(){
  Serial.print("valor Temperatura: ");
  Serial.print(_temperatura);//Print temperatura
  Serial.println("*C");
}


void lerValorTDS(){
    gravityTds.setTemperature(_temperatura);  // Pega o valor da temperatura e realiza a compensação
    gravityTds.update();  //Caucula
    _tdsValue = gravityTds.getTdsValue();  // Pega o valor do TDS
}
void printTDS(){
  Serial.print("valor ppm: ");
   Serial.print(_tdsValue,0);
   Serial.println("ppm");
}

void lerValorPh(){
    _ph = ph.pegaValorPhMedia(20);
}
void printPh(){
   Serial.print("valor ph: ");
   Serial.println(_ph);
}

void lerValorTurbidez(){
    _turbidez = turbidez.pegaValorTurbidezMedia();
}
void printTurbidez(){
   Serial.print("valor turbidez: ");
   Serial.println(_turbidez);
}
