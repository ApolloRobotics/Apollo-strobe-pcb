
#include <TinyWireS.h>
int I2C_SLAVE_ADDR = 0x26;
int blink = 0;
int on =0;
byte byteRcvd;
void setup() {
  // put your setup code here, to run once:
  TinyWireS.begin(I2C_SLAVE_ADDR);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); 
  delay(250);
   digitalWrite(4, HIGH); 
  delay(250);
   digitalWrite(4, LOW); 
  delay(250);
   digitalWrite(4, HIGH); 
  delay(250);
  digitalWrite(4, LOW); 
  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(100);
  
  if (TinyWireS.available()){           // got I2C input!
    byteRcvd = TinyWireS.receive();  
    on=1;                               // get the byte from master
    //digitalWrite(4, HIGH); 
    if(byteRcvd =0x4f){
      blink =1;
      
    }
    
    }
  if(blink){
    if(on){
      digitalWrite(4, LOW);
      on=0;
    }else{
      digitalWrite(4, HIGH);
      on=1;
    }
    //Blink(LED1_PIN,byteRcvd);           // master must wait for this to finish before calling Wire.requestFrom
    //byteRcvd += 10;                     // add 10 to what's received
   //TinyWireS.send(byteRcvd);           // send it back to master
                                         // show we transmitted
  }
}


