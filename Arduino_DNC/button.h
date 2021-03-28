#include "stdafx.h"

class Button
{
 public:
      uint8_t TextSize;
      uint16_t TextColor; 
      uint16_t BGColor;
      uint16_t x1;
      uint16_t y1;
      uint16_t x2;
      uint16_t y2;
      const char *str;
      void (*OnButtonTouched)();
      Button();
      Button(const char *str,uint16_t x,uint16_t y, uint16_t width, uint16_t height,bool draw =false);
      void Draw();
      void ButtonTouched();
};
