
#include "Extended.h"


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

void Boot (){
   tft.initR(INITR_BLACKTAB); 
   Serial.begin(9600);
   tft.setRotation(3);
   tft.setTextWrap(false);
   tft.fillScreen(ST7735_BLACK);
   tft.setTextColor(ST7735_BLUE);
   tft.setTextSize(2);
   tft.setCursor(25, 50); 
   tft.println("Walking");
   tft.setCursor(50, 70); 
   tft.println("Machine");
}

void DrawBattery(){
  tft.drawRoundRect(0, 0, 59, 40, 8, ST7735_WHITE); //big rectangle  
  tft.fillRoundRect(58, 12, 10, 15, 3, ST7735_WHITE); //fill little rect  
}

void UpdateBattery(int iPercent){
  if(iPercent > 22){ // mise à jour dynamique du rectangle de la batterie
    tft.fillRoundRect(1, 1, 57*iPercent/100, 38, 8, ST7735_GREEN); //big dynamic rect
    tft.drawPixel(6,1, ST7735_GREEN);
    tft.drawPixel(4,2, ST7735_GREEN);
    tft.drawPixel(3,3, ST7735_GREEN);
    tft.drawPixel(2,4, ST7735_GREEN);
    tft.drawPixel(1,6, ST7735_GREEN);
    
    tft.drawPixel(6,38, ST7735_GREEN);
    tft.drawPixel(4,37, ST7735_GREEN);
    tft.drawPixel(3,36, ST7735_GREEN);
    tft.drawPixel(2,35, ST7735_GREEN);
    tft.drawPixel(1,33, ST7735_GREEN);
  }
  else if ((iPercent <= 22) && (iPercent > 20)){ // fin de la mise à jour dynamique du rectangle
    tft.fillRoundRect(1, 1, 57*22/100, 38, 8, ST7735_GREEN);     
    tft.drawPixel(5,1, ST7735_WHITE);
    tft.drawPixel(4,2, ST7735_GREEN);
    tft.drawPixel(3,3, ST7735_GREEN);
    tft.drawPixel(2,4, ST7735_GREEN);
    tft.drawPixel(1,6, ST7735_GREEN);
         
    tft.drawPixel(5,38, ST7735_WHITE);
    tft.drawPixel(4,37, ST7735_GREEN);
    tft.drawPixel(3,36, ST7735_GREEN);
    tft.drawPixel(2,35, ST7735_GREEN);
    tft.drawPixel(1,33, ST7735_GREEN);
  }
  else{ // Batterie à 20% ou en dessous
    tft.fillRoundRect(1, 1, 57*22/100, 38, 8, ST7735_RED);      
    tft.drawPixel(5,1, ST7735_WHITE);
    tft.drawPixel(4,2, ST7735_RED);
    tft.drawPixel(3,3, ST7735_RED);
    tft.drawPixel(2,4, ST7735_RED);
    tft.drawPixel(1,6, ST7735_RED);
         
    tft.drawPixel(5,38, ST7735_WHITE);
    tft.drawPixel(4,37, ST7735_RED);
    tft.drawPixel(3,36, ST7735_RED);
    tft.drawPixel(2,35, ST7735_RED);
    tft.drawPixel(1,33, ST7735_RED);
  }
  //traitement de la valeur en pourcentage
  if(iPercent == 100){ //100%
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(2);
   tft.setCursor(88, 13);
   tft.println(iPercent);
   tft.setCursor(125, 13);
   tft.println("%");  
  }
  else if (iPercent >= 10){ // entre 10 et 100
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(2);
   tft.setCursor(95, 13);
   tft.println(iPercent);
   tft.setCursor(120, 13);
   tft.println("%");   
  }
  else{ // en dessous de 10%
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(2);
   tft.setCursor(100, 13);
   tft.println(iPercent);
   tft.setCursor(115, 13);
   tft.println("%");
  }
}

void PrintVoltage (float fVolt){ // affichage voltage
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(1);
   tft.setCursor(3, 50);
   tft.println("Volt:");
   tft.setCursor(35, 50);
   tft.println(fVolt);   
}

void PrintWH (float fWattHeure){ // affichage WattHeure
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(1);
   tft.setCursor(3, 66);
   tft.println("WattHeure:");
   tft.setCursor(64, 66);
   tft.println(fWattHeure);   
}

void PrintAH (float fAmpHeure){ // affichage AmpereHeure
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(1);
   tft.setCursor(3, 82);
   tft.println("AmpHeure:");
   tft.setCursor(59, 82);
   tft.println(fAmpHeure);   
}

void CleanScreenBlack (){   
   tft.fillScreen(ST7735_BLACK);
}

void PrintCanauxScreen(){
   tft.setTextColor(ST7735_WHITE);
   tft.setTextSize(2);
   tft.setCursor(38, 0);
   tft.println("Canaux");   
   tft.setTextSize(1);
   tft.setCursor(57, 25);
   tft.println("Canal 1");   
   tft.setCursor(57, 40);
   tft.println("Canal 2");   
   tft.setCursor(57, 55);
   tft.println("Canal 3");   
   tft.setCursor(57, 70);
   tft.println("Canal 4");
   tft.setCursor(57, 85);
   tft.println("Canal 5");
   tft.setCursor(57, 100);
   tft.println("Canal 6");
   tft.setCursor(57, 115);
   tft.println("Canal 7");   
}

void SelectCanal(int iSel){
  if(iSel==0){
    iSel = 1;
  }
  do{
  switch(iSel){
    case 1 :      
      tft.fillRect(0, 23, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 25);
      tft.println("Canal 1");
      break; 
    case 2 :
      tft.fillRect(0, 38, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 40);
      tft.println("Canal 2"); 
      break;
    case 3 :
      tft.fillRect(0, 53, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 55);
      tft.println("Canal 3"); 
      break;  
    case 4 :
      tft.fillRect(0, 68, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 70);
      tft.println("Canal 4");  
      break; 
    case 5 :
      tft.fillRect(0, 83, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 85);
      tft.println("Canal 5");   
      break;
    case 6 :
      tft.fillRect(0, 98, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 100);
      tft.println("Canal 6");  
      break; 
    case 7 :
      tft.fillRect(0, 113, 160, 11, ST7735_WHITE); //big rectangle
      tft.setTextColor(ST7735_BLACK);
      tft.setTextSize(1);
      tft.setCursor(57, 115);
      tft.println("Canal 7"); 
      break;    
    default :
      CleanScreenBlack();
      break;    
  }
  while(((digitalRead(pinButtonPrev))==0)||((digitalRead(pinButtonNext))==0)||((digitalRead(pinButtonValid))==0)||((digitalRead(pinButtonCancel))==0)){}
  if (digitalRead(pinButtonNext)){
    while (digitalRead(pinButtonNext)){}
    if(iSel == 7){
      iSel = 1;
    }
    else{
      iSel++;      
    }
  }
  else if (digitalRead(pinButtonPrev)){
    while (digitalRead(pinButtonPrev)){}
    if(iSel == 1){
      iSel = 7;
    }
    else{
      iSel--;      
    }
  }
  else if (digitalRead(pinButtonValid)){
    while(digitalRead(pinButtonValid)){}
      CleanScreenBlack ();
      tft.setTextColor(ST7735_WHITE);
      tft.setTextSize(1);
      tft.setCursor(57, 25);
      tft.println("Canal ");
      tft.setCursor(68, 25);
      tft.println(iSel);    
  }
  }while(digitalRead(pinButtonCancel)==0);
  CleanScreenBlack();
  PrintCanauxScreen();
}

