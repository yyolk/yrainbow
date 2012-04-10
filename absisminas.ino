void drawAbsisMinas(byte f[]){

//  int f[3] = {255, 6, 250};


  setPixel(1, 0, f[0], f[1], f[2]);
  setPixel(1, 1, f[0], f[1], f[2]);
  setPixel(2,0, f[0], f[1], f[2]);
  setPixel(2, 1, f[0], f[1], f[2]);
  setPixel(5, 0, f[0], f[1], f[2]);
  setPixel(5, 1, f[0], f[1], f[2]);
  setPixel(6, 0, f[0], f[1], f[2]);
  setPixel(6, 1, f[0], f[1], f[2]);
//  setPixel(0, 7, f[0], f[1], f[2]);
//  setPixel(7, 7, f[0], f[1], f[2]);
    setPixel(1, 7, f[0], f[1], f[2]);
  setPixel(2, 6, f[0], f[1], f[2]);
  setPixel(3, 6, f[0], f[1], f[2]);

  setPixel(4, 6, f[0], f[1], f[2]);
  setPixel(5, 6, f[0], f[1], f[2]);
  setPixel(6, 7, f[0], f[1], f[2]);
  //byte offc[3]={random(0xf),random(0xf),random(0xf)};
  //byte offc[3]={f[0], f[1], f[2]};
  byte offc[] = {*f*random(2000)%255, *f*random(2000)%255, *f*random(2000)%255};
//  for (int i=0; i<4; i++){
//     //offc[i] = random(0xf);
//      offc[i] = (0,0,90);
//  }
  
  animatedTears(offc);
  
}


void animatedTears(byte offc[]){
//  int f[3] = { 255, 6, 250 };
//  int f[3] = { random(255), random(255), random(255) };
  int f[3] = {0, 25, 230};
  int dd = 25;
  
  delay(dd*6);
  setPixel(1,2, f[0], f[1], f[2]);
  setPixel(6,2, f[0], f[1], f[2]);
  
  delay(dd*2);
  
  setPixel(1,2, offc[0], offc[1], offc[2]);
  setPixel(6,2, offc[0], offc[1], offc[2]);
  
  delay(dd);
  
//  setPixel(1,3, f[0], f[1], f[2]);
//  setPixel(0,3, f[0], f[1], f[2]);
//  setPixel(1,4, f[0], f[1], f[2]);
  setPixel(1,3, f[0], f[1], f[2]);
  setPixel(6,3, f[0], f[1], f[2]);
  
  delay(dd*2);
  
//  setPixel(1,3, 0,0,0);
//  setPixel(0,3, 0,0,0);
//  setPixel(1,4, 0,0,0);
  setPixel(1,3, offc[0], offc[1], offc[2]);
  setPixel(6,3, offc[0], offc[1], offc[2]);  
  delay(dd);
  
//  setPixel(0,4, f[0], f[1], f[2]);
//  setPixel(0,3, f[0], f[1], f[2]);
//  setPixel(1,5, f[0], f[1], f[2]);

  setPixel(1,4, f[0], f[1], f[2]);
  setPixel(6,4, f[0], f[1], f[2]);
  
  delay(dd*2);
//  setPixel(0,4, 0,0,0);
//  setPixel(0,3, 0,0,0);  
//  setPixel(1,5, 0,0,0);
  
  setPixel(6,4, offc[0], offc[1], offc[2]);
  setPixel(1,4, offc[0], offc[1], offc[2]);
  
  delay(dd);
  
  setPixel(1,5, f[0], f[1], f[2]);
  setPixel(6,5, f[0], f[1], f[2]);
  
  delay(dd*2);
  
    setPixel(1,5, offc[0], offc[1], offc[2]);
  setPixel(6,5, offc[0], offc[1], offc[2]);
  
}
