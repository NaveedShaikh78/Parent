#include "button.h"
#include "lcd.h"

 Button::Button()
 {
//_ButtonTouched = &Button::Draw;
//pmf = &A::g;

 // ((Button*)this)->Button::_ButtonTouched();
 }
 
 Button::Button(const char *_str,uint16_t _x,uint16_t _y, uint16_t _width, uint16_t _height, bool draw)
 {
  str = _str;
  x1 = map(_x, TS_MINX, TS_MAXX, TFT::LCD.Get_Display_Width(), 0);
  y1 = map(_y, TS_MINY, TS_MAXY, TFT::LCD.Get_Display_Height(),0);
  x2 = x1+ _width;
  y2 = y1+ _height;
  if(draw)
  {
   Draw();
  }
 }
void Button::ButtonTouched()
{
  TFT::LCD.Set_Draw_color(DCYAN);
  TFT::LCD.Fill_Rectangle(x1, y1, x2, y2);  
  TFT::LCD.Set_Text_colour(BLACK);
  TFT::LCD.Set_Text_Back_colour(DCYAN);
  TFT::LCD.Print_String(str,x1+20,y1+20);
  (*OnButtonTouched)();
  Draw();
}
void Button::Draw()
{
  TFT::LCD.Set_Text_Size(3);
  TFT::LCD.Set_Draw_color(CYAN);
  TFT::LCD.Fill_Rectangle(x1, y1, x2, y2);  
  TFT::LCD.Set_Draw_color(DCYAN);
  TFT::LCD.Draw_Rectangle(x1, y1, x2, y2);  
  TFT::LCD.Draw_Rectangle(x1+1, y1+1, x2+1, y2+1);  
  TFT::LCD.Set_Text_colour(BLACK);
  TFT::LCD.Set_Text_Back_colour(CYAN);
  TFT::LCD.Print_String(str,x1+20,y1+20);
}
