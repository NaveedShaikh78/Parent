#include "button.h"
#include "lcd.h"

 Button::Button()
 {
 }
 Button::Button(const char *str,uint16_t _x,uint16_t _y, uint16_t _width, uint16_t _height, bool draw)
 {
  x = map(_x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
  y = map(_y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
 //   x = _x, 
  //    y = _y, 
  width = x+ _width;
  height = y+ _height;
  if(draw)
  {
   Draw();
  }
 }

void Button::Draw()
{
  TFT::LCD.Set_Draw_color(GREEN);
  TFT::LCD.Fill_Round_Rectangle(x, y, width, height, 5);  
  
}
