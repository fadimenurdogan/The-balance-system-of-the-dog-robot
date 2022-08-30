#include "Arduino.h"
#include "HX711.h"        //  Library to use HX711 strain gage converter
#include <Wire.h>

byte okunan[4];
#define DOUT1  3        //  Load Cell A pin connections
#define CLK1  2
#define calibration_factor -8000.0
#define DOUT2  5        //  Load Cell B pin connections
#define CLK2  4

#define DOUT3  7      //  Load Cell A pin connections
#define CLK3  6

#define DOUT4  9        //  Load Cell B pin connections
#define CLK4  8
HX711 scale1(DOUT1, CLK1);
HX711 scale2(DOUT2, CLK2);
HX711 scale3(DOUT3, CLK3);
HX711 scale4(DOUT4, CLK4);


void setup() {
  Serial.begin(9600);
  scale1.begin(DOUT1, CLK1);
  scale1.set_scale(calibration_factor);
  scale1.tare();
  
  scale2.begin(DOUT2, CLK2);
  scale2.set_scale(calibration_factor);
  scale2.tare();

  scale3.begin(DOUT3, CLK3);
  scale3.set_scale(calibration_factor);
  scale3.tare();
  
  scale4.begin(DOUT4, CLK4);
  scale4.set_scale(calibration_factor);
  scale4.tare();
  
  Wire.begin(1); // Cihaz slave olarak çalışacak ve ID adresi 1 olacak
  Wire.onRequest(cevap); // İstek geldiğinde cevap fonksiyonu çalışacak
}
    void loop(){
       
}
    void cevap(){

        byte sol_on = scale1.get_units();
        byte sol_arka = scale2.get_units();
        byte sag_on = scale3.get_units(); 
        byte sag_arka = scale4.get_units();
        delay(10);
        byte okunan[]={sol_on, sol_arka, sag_on, sag_arka};
 Serial.print("weight_1 ");
 Serial.print(scale1.get_units(),1);
 Serial.print("     weight_2 ");
 Serial.print(scale2.get_units(),1);
 Serial.print("     weight_3 ");
 Serial.print(scale3.get_units(),1);
 Serial.print("     weight_4 ");
 Serial.println(scale4.get_units(),1);
        Wire.write(okunan, 4);
    }
  // 10 milisaniye
