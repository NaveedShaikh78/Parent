
/***********************************************************************************
DNC Software 
Auther : Naveed Shaikh
**********************************************************************************/
#include "stdafx.h"
#include "lcd.h"

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

//param calibration from kbv
#define TS_MINX 906
#define TS_MAXX 116

#define TS_MINY 92 
#define TS_MAXY 952

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TFT TFT_LCD; 

uint16_t color_mask[] = {0xF800,0xFFE0,0x07E0,0x07FF,0x001F,0xF81F}; //color select

#define COLORBOXSIZE TFT::LCD.Get_Display_Width()/6
#define PENBOXSIZE TFT::LCD.Get_Display_Width()/4

int16_t old_color, current_color,flag_colour;
int16_t old_pen,current_pen,flag_pen;
boolean show_flag = true;

//show color select menu
void show_color_select_menu(void)
{
   uint16_t i;
   for(i = 0;i<6;i++)
   {
       TFT::LCD.Set_Draw_color(color_mask[i]);
       TFT::LCD.Fill_Rectangle(i*COLORBOXSIZE, 0, (i+1)*COLORBOXSIZE-1, COLORBOXSIZE/2-1);
   }  
   TFT::LCD.Set_Draw_color(GREEN);
   TFT::LCD.Fill_Round_Rectangle((TFT::LCD.Get_Display_Width()-20)/3+10, COLORBOXSIZE/2+2, (TFT::LCD.Get_Display_Width()-20)/3*2+10,COLORBOXSIZE/2+20, 5);
   TFT_LCD.ShowString("OK",CENTER,COLORBOXSIZE/2+4,2,RED, BLACK,1);
}



//show main menu
void show_main_menu(void)
{
   TFT::LCD.Set_Draw_color(YELLOW);
   TFT::LCD.Fill_Round_Rectangle(5, 0, (TFT::LCD.Get_Display_Width()-20)/3+5,COLORBOXSIZE/2+20, 5);
   TFT::LCD.Fill_Round_Rectangle((TFT::LCD.Get_Display_Width()-20)/3*2+15, 0, (TFT::LCD.Get_Display_Width()-20)/3*3+15,COLORBOXSIZE/2+20, 5);
   TFT::LCD.Set_Draw_color(MAGENTA);
   TFT::LCD.Fill_Round_Rectangle((TFT::LCD.Get_Display_Width()-20)/3+10, 0, (TFT::LCD.Get_Display_Width()-20)/3*2+10,COLORBOXSIZE/2+20, 5);
   TFT_LCD.ShowString("COLOUR",5+((TFT::LCD.Get_Display_Width()-20)/3-72)/2-1,((COLORBOXSIZE/2+20)-16)/2,2,BLUE, BLACK,1);
   TFT_LCD.ShowString("CLEAR",(TFT::LCD.Get_Display_Width()-20)/3+10+((TFT::LCD.Get_Display_Width()-20)/3-60)/2-1,((COLORBOXSIZE/2+20)-16)/2,2,WHITE, BLACK,1);
   TFT_LCD.ShowString("PENSIZE",(TFT::LCD.Get_Display_Width()-20)/3*2+15+((TFT::LCD.Get_Display_Width()-20)/3-84)/2-1,((COLORBOXSIZE/2+20)-16)/2,2,BLUE, BLACK,1);
 }

void setup(void) 
{
  Serial.begin(9600);
  TFT::LCD.Init_LCD();
  Serial.println(TFT::LCD.Read_ID(), HEX);
  TFT::LCD.Fill_Screen(BLACK);
  show_main_menu();
  current_color = RED;
  current_pen = 0;
  pinMode(13, OUTPUT);

}



void loop()
{
comme:
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z >= MINPRESSURE) 
  {
      if (p.y < (TS_MINY-5)) 
      {
          TFT::LCD.Set_Draw_color(BLACK);
          TFT::LCD.Fill_Rectangle(0, COLORBOXSIZE, TFT::LCD.Get_Display_Width()-1, TFT::LCD.Get_Display_Height()-1);
      }
      //p.x = TFT::LCD.Get_Display_Width()-map(p.x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
      //p.y = TFT::LCD.Get_Display_Height()-map(p.y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(), 0);
      p.x = map(p.x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
      p.y = map(p.y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
      
      if (((p.y-current_pen) > COLORBOXSIZE/2+20) && ((p.y+current_pen) < TFT::LCD.Get_Display_Height()))  //drawing
      {
        TFT::LCD.Set_Draw_color(current_color);
       // if(1 == current_pen)
     //   {
      //      TFT::LCD.Draw_Pixel(p.x,  p.y);
     //   }
     //   else 
     //   {
          TFT::LCD.Fill_Circle(p.x,  p.y,current_pen);
      //  }
    }
  }
}
