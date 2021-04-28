#include "LedControlMS.h"

// pin 4 is connected to the DataIn
// pin 3 is connected to the CLK
// pin 2 is connected to LOAD

#define NBR_MTX 1 //number of matrices attached is one
LedControl lc=LedControl();//

 void setup()
{
  for (int i=0; i< NBR_MTX; i++)
  {
    lc.
    /* Set the brightness to a medium values */
    lc.
    /* and clear the display */
    lc.

    delay(100);
  }
}

void loop()
{
  //sending characters to display
  
  //clearing the display
  lc.clearAll();

  delay(3000);
}
