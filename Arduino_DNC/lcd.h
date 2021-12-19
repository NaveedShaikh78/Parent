#include "stdafx.h"


#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

#define MINPRESSURE 500

class TFT
{
	public:
      static LCDWIKI_KBV LCD; //model,cs,cd,wr,rd,reset;
      void ShowString(const char *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode);
};
