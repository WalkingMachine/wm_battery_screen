#include "Extended.h"

int iPercent;
float fVoltage = 23;
float fWattHeure = 518.665;
float fAmpHeure = 518.665;
bool  bScreenP = 0; //1 si sur batterie 0 sur canaux
int   iScreenS =0;

void setup() {
     // put your setup code here, to run once:
     Boot();
     pinMode(pinButtonValid, INPUT);     
     pinMode(pinButtonCancel, INPUT);     
     pinMode(pinButtonNext, INPUT);
     pinMode(pinButtonPrev, INPUT);
     delay(2000);
     CleanScreenBlack();
     DrawBattery();
     iPercent = fVoltage/24*100;
     UpdateBattery(iPercent);
     PrintVoltage(fVoltage);
     PrintWH(fWattHeure); 
     PrintAH(fAmpHeure);
}

void loop() {
    // put your main code here, to run repeatedly:      
    if(((digitalRead(pinButtonNext)) || (digitalRead(pinButtonPrev))) && iScreenS == 0){
      bScreenP = !bScreenP ;
      if(digitalRead(pinButtonNext)){
        while(digitalRead(pinButtonNext)){};
      }
      else if (digitalRead(pinButtonPrev)){
         while(digitalRead(pinButtonPrev)){};
      }
      CleanScreenBlack();
      if (bScreenP){       
        PrintCanauxScreen(); 
      }
      else{
        DrawBattery();
        iPercent = fVoltage / 24 * 100;
        UpdateBattery(iPercent);
        PrintVoltage(fVoltage);
        PrintWH(fWattHeure); 
        PrintAH(fAmpHeure);
      }
    }
    if (bScreenP && (digitalRead(pinButtonValid))){
          while(digitalRead(pinButtonValid)){};
          SelectCanal(iScreenS);
        }     
      
}
