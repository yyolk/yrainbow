
unsigned char gamma[16] = {0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7};


// be careful with very large blocks of the same value (like 0xff or 0x00)
// there may be arbitrary upload fails (byte mismatches)!!

// this multidimensional buffer stores the values for the individual leds
// first dimension groups the three colors
// always two leds are together in one unsigned char (= byte) for saving space
// --> [3][8][4] not [3][8][8]
// brightness setting of an individual led ranges [0..f] in this firmware
unsigned char buffer[3][8][4] = 
  // shown after boot-up
  // all leds set to 0xf -> all leds light up
{
  {
    // FIXME: change to RGB rather than GRB...
    
    
    // GREEN
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff}
  },
  { 
    // RED
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff}
  },
  { 
    // BLUE
    {0xff,0xff,0xff,0xff}, 
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff}
  }
};
