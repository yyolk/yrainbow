

#include "Rainbow.h"

extern byte buffer[3][8][4]; // display buffer, see data.c
extern byte gamma[16];
byte line, level;


void blackblack(int* blk[]);
int* blk[]={0, 0, 0};
void fuschiafuschia(int* fuschia[]);
//int* fuschia[] = {0,0,0};
int* fuschia[]={0, 0, 0};



void setup()
{
  _init();

  
}


//
//
// main loop
void loop()
{
  
  fillCanvas(random(255),random(255),random(255));
  delay(25);
  drawAbsisMinas();
}

void randomDots(){
   for (int i=0; i<8; i++){
      for (int j=0; j<8; j++){
        setPixel(i,j, random(255), random(255), random(255));
   } 
   }
}




  
void fillCanvas(int c1, int c2, int c3){

  
  int c[] = {c1, c2, c3};

  
  
  for (byte x = 0; x < 8; x++)
  {
    for (byte y = 0; y < 8; y++)
      setPixel(x, y, c[0], c[1], c[2]);
  }
}




// FIXME
//// use this to set individual leds
//void setLED(byte n, byte brightness)
//{
//  byte xbrightness, xx, xy, msk;
//  xx = n / 7;
//  xy = n % 7;
//  
//  if (!(xx % 2))
//  {
//    xbrightness = (brightness << 4);
//    msk = 0x0f;
//  }
//  else
//  {
//    xbrightness = brightness & 0x0f;
//    msk = 0xf0;
//  }
//  
//  if (n >= 128)
//  {
//    xx -= 16;
//    xx /= 2;
//    buffer[0][xy][xx] = xbrightness | (buffer[0][xy][xx] & msk);
//    return;
//  }
//  else if (n >= 64)
//  {
//    xx -= 8;
//    xx /= 2;
//    buffer[1][xy][xx] = xbrightness | (buffer[1][xy][xx] & msk);
//    return;
//  }
//  else
//  {
//    xx /= 2;
//    buffer[2][xy][xx] = xbrightness | (buffer[2][xy][xx] & msk);
//  }
//}

byte *randomColorTriplet(){
  byte *pa, array[3];
  for (int i=0; i<3; i++){
      array[i] = random(255);
      
  }  
  pa = &array[0];

  return pa; 
}

// this function sets one 'pixel', i.e. three leds at a time
// use this if you have a 8x8 led matrix
void setPixel(byte x, byte y, byte r, byte g, byte b)
{  
  byte xr, xg, xb, xx, xy, msk;
  xx = x & 7;
  xy = y & 7;
  
  if (!(xx % 2))
  {
    xr = (r << 4);
    xg = (g << 4);
    xb = (b << 4);
    msk = 0x0f;
  }
  else
  {
    xr = r & 0x0f;
    xg = g & 0x0f;
    xb = b & 0x0f;
    msk = 0xf0;
  }
  
  xx /= 2;

  buffer[0][xy][xx] = xg | (buffer[0][xy][xx] & msk);
  buffer[1][xy][xx] = xr | (buffer[1][xy][xx] & msk);
  buffer[2][xy][xx] = xb | (buffer[2][xy][xx] & msk);
}



// =================================================
// internal stuff -- didn't really touch that at all
// just reformated for enhanced readability

ISR(TIMER2_OVF_vect)
{ 
  TCNT2 = gamma[level];
  flash_next_line(line, level);
  line++;
  if (line > 7)
  {
    line = 0;
    level++;
    if(level > 15)
      level = 0;
  }
}


void init_timer2()               
{
  TCCR2A |= (1 << WGM21) | (1 << WGM20);   
  TCCR2B |= (1 << CS22);
  TCCR2B &= ~((1 << CS21) | (1 << CS20));
  TCCR2B &= ~((1 << WGM21) | (1 << WGM20));
  ASSR |= (0 << AS2);
  TIMSK2 |= (1 << TOIE2) | (0 << OCIE2B);
  TCNT2 = gamma[0];
  sei();   
}


void _init()
{
  DDRD = 0xff;
  DDRC = 0xff;
  DDRB = 0xff;
  PORTD = 0;
  PORTB = 0;
  level = 0;
  line = 0;
  init_timer2();
}


void shift_1_bit(unsigned char LS)
{
  if (LS)
  {
    shift_data_1;
  }
  else
  {
    shift_data_0;
  }
  clk_rising;
}


void flash_next_line(unsigned char line, unsigned char level)
{
  disable_oe;
  close_all_line;
  open_line(line);
  shift_24_bit(line, level);
  enable_oe;
}


void shift_24_bit(unsigned char line, unsigned char level)
{
  unsigned char color = 0, row = 0;
  unsigned char data0 = 0, data1 = 0;
  
  le_high;
  for (color = 0; color < 3; color++)
  {
    for (row = 0; row < 4; row++)
    {
      data1 = buffer[color][line][row] & 0x0f;
      data0 = buffer[color][line][row] >> 4;

      if (data0 > level)
      {
        shift_1_bit(1);
      }
      else
      {
        shift_1_bit(0);
      }

      if (data1 > level)
      {
        shift_1_bit(1);
      }
      else
      {
        shift_1_bit(0);
      }
    }
  }
  le_low;
}


void open_line(unsigned char line)
{
  switch (line)
  {
    case 0: open_line0; break;
    case 1: open_line1; break;
    case 2: open_line2; break;
    case 3: open_line3; break;
    case 4: open_line4; break;
    case 5: open_line5; break;
    case 6: open_line6; break;
    case 7: open_line7; break;
  }
}

