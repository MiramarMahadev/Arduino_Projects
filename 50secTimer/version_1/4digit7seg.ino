#include <TM1637Display.h>
#define Buzzer 0
#define CLK 1
#define DIO 2
#define DELAY 930
TM1637Display display(CLK, DIO);

void setup()
{pinMode(Buzzer,OUTPUT);
}

void loop(){
  display.setBrightness(10);
  for(int k = 50; k > 0; k--){
     if (k > 0 && k < 3 )
       digitalWrite(Buzzer,1);
     else
      digitalWrite(Buzzer,0);
     
    display.showNumberDec(k);      
    delay(DELAY);
  }
}
