
/*

  simple-rainbowduino-jmr-v1.pde
    
  written by Johannes M. Roth on 10.03.2011
  visit the project home at http://code.google.com/p/simple-rainbowduino-jmr/
  
  
  This Arduino sketch should be compatible with both the older version of
  the Rainbowduino (ATmega168) and the current release (ATmega328).
  
  I wrote it because - i'm sorry - Seeedstudio suuc...
  I'm sorry. Hardware is fine, but don't expect any support.
  
  So, this is a *very basic* code for driving an Rainbowduino.
  No communication whatsoever is implemented. You are free to write your
  own protocol! Just one thing i stumbled upon during implementing a
  serial communication protocol: choose a high baud rate! Slow ones don't
  work -- i think maybe some interference with the interrupts?
  
  For flashing select board...
    "Arduino Diecimila, Duemilanove, or Nano w/ ATmega168"
  or
    "Arduino Duemilanove or Nano w/ ATmega328"
  depending on your revision and select the appropiate port.
    (on Mac OS X select "/dev/tty.usbserial*")
  
  If you have an USB-UART adapter connect Reset (or RST or DTR),
  Ground (GND), 5V to the terminal or the connector (don't forget to set
  the switch!) and RX to TXD and TX to RXD.
  If you have any Arduino (or compatible) see:
    http://code.google.com/p/rainbowduino-firmware/wiki/HowtoFlashViaUSB
  
  
  
  based on the Rainbowduino_Plasma.pde 'Color cycling plasma' by Ben Combee
  which is based on a version of Ken Corey
  which is based on a version of Windell H. Oskay
  ...i hope i got that right...
  (was available through the seeedstudio site, but i couldn't find it anymore)
  
  aaaand
  
  based on the Rainbowduino Firmware 3 by pacrox22-at-gmail-dot-com
  (have a look at http://code.google.com/p/rainbowduino-firmware/)
  
  
  This library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this library. If not, see http://www.gnu.org/licenses/
*/


#include "Rainbow.h"

extern byte buffer[3][8][4]; // display buffer, see data.c
extern byte gamma[16];
byte line, level;


void setup()
{
  _init();
}


void loop()
{
  // switches every dot dark
  for (byte x = 0; x < 8; x++)
  {
    for (byte y = 0; y < 8; y++)
      setPixel(x, y, random(0xf), random(0xf), random(0xf));
  }
  
//  delay(1000);
  
  // paint a smiley :)
//  setPixel(1, 1, 0xf, 0xf, 0xf);
//  setPixel(1, 2, 0xf, 0xf, 0xf);
//  setPixel(2, 1, 0xf, 0xf, 0xf);
//  setPixel(2, 2, 0xf, 0xf, 0xf);
//  setPixel(5, 1, 0xf, 0xf, 0xf);
//  setPixel(5, 2, 0xf, 0xf, 0xf);
//  setPixel(6, 1, 0xf, 0xf, 0xf);
//  setPixel(6, 2, 0xf, 0xf, 0xf);
//  setPixel(1, 5, 0xf, 0xf, 0xf);
//  setPixel(6, 5, 0xf, 0xf, 0xf);
//  setPixel(2, 6, 0xf, 0xf, 0xf);
//  setPixel(3, 6, 0xf, 0xf, 0xf);
//  setPixel(4, 6, 0xf, 0xf, 0xf);
//  setPixel(5, 6, 0xf, 0xf, 0xf);


// paint a YOOKLK
for (int ii = 0; ii < 100; ii++){
    for (byte x = 0; x < 8; x++)
  {
    for (byte y = 0; y < 8; y++)
    
      setPixel(x, y, random(0xf), random(0xf), random(0xf));
    for (byte j=0 ; j< 10 ; j++){

    
  }
  
}
     drawSmiley(0xf);
    delay(50);
    drawSmiley(0);
    delay(50);
    drawFrowny(0xf);
    delay(25);
    drawFrowny(0);
    delay(25);
}




}
void drawSmiley(byte color){
         setPixel(1, 1, color, color, color);
  setPixel(1, 2, color, color, color);
  setPixel(2, 1, color, color, color);
  setPixel(2, 2, color, color, color);
  setPixel(5, 1, color, color, color);
  setPixel(5, 2, color, color, color);
  setPixel(6, 1, color, color, color);
  setPixel(6, 2, color, color, color);
  setPixel(1, 5, color, color, color);
  setPixel(6, 5, color, color, color);
  setPixel(2, 6, color, color, color);
  setPixel(3, 6, color, color, color);
  setPixel(4, 6, color, color, color);
  setPixel(5, 6, color, color, color); 
}

void drawFrowny(byte color){
  setPixel(1, 1, color, color, color);
  setPixel(1, 2, color, color, color);
  setPixel(2, 1, color, color, color);
  setPixel(2, 2, color, color, color);
  setPixel(5, 1, color, color, color);
  setPixel(5, 2, color, color, color);
  setPixel(6, 1, color, color, color);
  setPixel(6, 2, color, color, color);
  setPixel(1, 6, color, color, color);
  setPixel(6, 6, color, color, color);
  setPixel(2, 5, color, color, color);
  setPixel(3, 5, color, color, color);
  setPixel(4, 5, color, color, color);
  setPixel(5, 5, color, color, color);
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

