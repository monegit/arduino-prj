#include "LedControlMS.h"

#define NBR_MTX 1 //number of matrices attached is one

LedControl lc=LedControl(4,3,2, NBR_MTX);//

unsigned long delayTime=1200;  // Delay between Frames

// Put values in arrays
byte heart_empty_model[] =
{
   B00100100,  
   B01011010,
   B10000001,
   B10000001,
   B10000001,
   B01000010,
   B00100100,
   B00011000
};

byte heart_full_model[] =
{
  B00000000, 
  B01100110,
  B11111111,
  B11111111, 
  B11111111,
  B01111110,
  B00111100,
  B00011000
};


void setup()
{
    lc.shutdown(0,false);
    lc.setIntensity(0,5);
    lc.clearDisplay(0);
}


//  Take values in Arrays and Display them
void heart()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,heart_empty_model[i]);
  }
}

void heart_full()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,heart_full_model[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
    
    delay(delayTime);
    heart();
    delay(delayTime);


// Put #2 frame on both Display
    
    delay(delayTime);
    heart_full();
    delay(delayTime);

}
