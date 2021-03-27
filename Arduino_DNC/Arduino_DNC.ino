
/***********************************************************************************
DNC Software 
Auther : Naveed Shaikh
**********************************************************************************/
#include "stdafx.h"
#include "lcd.h"
#include "button.h"

// For better pressure precision, we need to know the resistance
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 600);
Button btnList[3];
TFT TFT_LCD; 


//show main menu
void show_main_menu(void)
{
   int _x = map(200, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
   int _y = map(100, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
  // Button("Hello",18,50,20,20,true);
   Button button("Send",100,50,20,20,true);
   Button button1("Receive",100,50,20,20,true);
   
 }

void setup(void) 
{
  Serial.begin(9600);
  TFT::LCD.Init_LCD();
  Serial.println(TFT::LCD.Read_ID(), HEX);
  TFT::LCD.Fill_Screen(BLACK);
  show_main_menu();

}



void loop()
{

  TSPoint p = ts.getPoint();
  //digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z >= MINPRESSURE) 
  {
      
      Button button("",p.x,  p.y,5, 5,2);
     
      p.x = map(p.x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
      p.y = map(p.y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
    
   
  }
}
