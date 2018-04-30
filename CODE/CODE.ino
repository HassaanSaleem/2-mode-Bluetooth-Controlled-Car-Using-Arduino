#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //TX, RX respetively
String readdata;
int x=0;

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(12,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() 
{
  int y=1;
  if(digitalRead(13)==LOW )   //Incrimneent
  {
      Serial.write(x);
      digitalWrite(3,HIGH);
      digitalWrite (4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      x++;
      BT.write(x);
      Serial.println(x,DEC);
      delay(100);
  }

  if(digitalRead(7)==HIGH)  //decrement
  {
      Serial.write(x);
      digitalWrite(3,LOW);
      digitalWrite (4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      x--;
      BT.write(x);
      Serial.println(x,DEC);
      delay(100);
  }
  
  while (BT.available())  //check if blutetooth is connected
  {
      delay(10); 
      char c = BT.read(); // Read From Bluetooth
      readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) 
  {
    Serial.println(readdata);  //To check on serial monitor
    
    if(readdata == "forward")
    {
       digitalWrite(3,HIGH);
       digitalWrite (4,LOW);
       digitalWrite(5,HIGH);
       digitalWrite(6,LOW);
       delay(100);
    }

    else if(readdata =="reverse")
    {
       digitalWrite(3,LOW);
       digitalWrite(4,HIGH);
       digitalWrite(5,LOW);
       digitalWrite(6,HIGH);
       delay(100);
    }

    else if (readdata=="right")
    {
        digitalWrite (3,LOW);
        digitalWrite (4,LOW);
        digitalWrite (5,LOW);
        digitalWrite (6,HIGH);
        delay (100);
   
    }

    else if (readdata=="left")
    {
        digitalWrite (3,LOW);
        digitalWrite (4,HIGH);
        digitalWrite (5,LOW);
        digitalWrite (6,LOW);
        delay (100);
    }

    else if(readdata=="stop")
    {
        digitalWrite (3,LOW);
        digitalWrite (4,LOW);
        digitalWrite (5,LOW);
        digitalWrite (6,LOW);
        delay (100);
    }
    
  readdata="";//Reset the string
  
  }
} 
