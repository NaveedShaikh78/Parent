#include "stdafx.h"


class TFT
{
	public:
      static LCDWIKI_KBV LCD; //model,cs,cd,wr,rd,reset;
      void ShowString(const char *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode);
};
