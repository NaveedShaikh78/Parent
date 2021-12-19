  #include "lcd.h"

LCDWIKI_KBV TFT::LCD(ILI9486,A3,A2,A1,A0,A4);

void  TFT::ShowString(const char *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    TFT::LCD.Set_Text_Mode(mode);
    TFT::LCD.Set_Text_Size(csize);
    TFT::LCD.Set_Text_colour(fc);
    TFT::LCD.Set_Text_Back_colour(bc);
    TFT::LCD.Print_String(str,x,y);
}
