
/***********************************************************************************
DNC Software 
Auther : Naveed Shaikh
**********************************************************************************/
#include "stdafx.h"
#include "lcd.h"
#include "button.h"
#define nbtn  3
// For better pressure precision, we need to know the resistance
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 500);

Button btnList[nbtn];
TFT TFT_LCD; 


//show main menu
void show_main_menu(void)
{
   int _x = map(200, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
   int _y = map(100, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
  // Button("Hello",18,50,20,20,true);
   btnList[0]= Button("Send",120,230,110,70,true);    btnList[0].OnButtonTouched = &Send;
   btnList[1]= Button("Rec.",385,230,110,70,true);    btnList[1].OnButtonTouched = &Receive;
   btnList[2]= Button("Brow.",645,230,110,70,true);   btnList[2].OnButtonTouched = &Browse;
 }

void setup(void) 
{
  Serial.begin(9600);
  TFT::LCD.Init_LCD();
  Serial.println(TFT::LCD.Read_ID(), HEX);
  TFT::LCD.Fill_Screen(BLACK);
  show_main_menu();

}

void Send()
{
  
  TFT::LCD.Set_Text_Size(3);
  TFT::LCD.Set_Text_colour(BLACK);
  TFT::LCD.Set_Text_Back_colour(GREEN);
  TFT::LCD.Print_String("Send",120+20,230+20);
}
void Receive()
{
  
  TFT::LCD.Set_Text_Size(3);
  TFT::LCD.Set_Text_colour(BLACK);
  TFT::LCD.Set_Text_Back_colour(RED);
  TFT::LCD.Print_String("Rec",120+20,230+20);
}
void Browse()
{
  
  TFT::LCD.Set_Text_Size(3);
  TFT::LCD.Set_Text_colour(BLACK);
  TFT::LCD.Set_Text_Back_colour(DCYAN);
  TFT::LCD.Print_String("Brow",120+20,230+20);
}

void loop()
{

  TSPoint p = ts.getPoint();
  //digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z >= MINPRESSURE) 
  {
      p.x = map(p.x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
      p.y = map(p.y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
      for(int i=0;i<nbtn;i++)
      {
          if(p.x>btnList[i].x1 && p.x<btnList[i].x2 && p.y>btnList[i].y1 && p.y<btnList[i].y2)
          {
            btnList[i].ButtonTouched();
          }
      } 
  }
}
