int DS_pin = 0;
int STCP_pin =1;
int SHCP_pin = 2 ;
int g1 = 3;
int g2 = 4;
int buzz = 5;
int dec_digits [10] ={252,96,218,242,102,182,190,224,254,246};

void setup() {

  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(g2, OUTPUT);
  
} 

void loop(){

  for(int i=50 ;i>=0;i--){
    if(i<=2 && i>=0){digitalWrite(buzz,1);}
    else {digitalWrite(buzz,0);}
     for(int j=0;j<50;j++){
      multiplex(i);
   
     }
  }

}

void multiplex(int num){

  int n = num % 10;
  digitalWrite(g2,0);
  dispnum(n);
  delay(10);
  digitalWrite(g2,1);
  num = num /10;
  n = num % 10;
  digitalWrite(g1,0);
  dispnum(n);
  delay(10);
  digitalWrite(g1,1);

}

void dispnum(int num){

  digitalWrite(STCP_pin,LOW);
  shiftOut(DS_pin, SHCP_pin, LSBFIRST,dec_digits[num]);
  digitalWrite(STCP_pin, HIGH);

}


 
