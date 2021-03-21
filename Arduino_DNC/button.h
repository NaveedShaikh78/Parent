#include "stdafx.h"

class Button
{
 public:
      uint8_t csize;
      uint16_t TextColor; 
      uint16_t BGColor;
      boolean mode;
      Button(const char *str,int8_t x,int8_t y, int8_t width, int8_t height);
};
