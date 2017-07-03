#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>

#define TFT_CS            10
#define TFT_RST            9 
#define TFT_DC             8
#define BUTTON             7
#define pinButtonValid     2
#define pinButtonCancel    4
#define pinButtonNext      3
#define pinButtonPrev      5


void Boot();
void DrawBattery();
void UpdateBattery(int);
void DrawRoundRect(int16_t, int16_t, int16_t, int16_t,uint16_t);
void PrintVoltage (float);
void PrintWH (float);
void PrintAH (float);
void CleanScreenBlack ();
void PrintCanauxScreen();
void PrintCanaux(int, float,int, float,int, float,int, float,int, float,int, float,int, float);
void SelectCanal(int);
