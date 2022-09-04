//Tinker CAD Link:https://www.tinkercad.com/things/cHztafWqfww-copy-of-lcd-indication-of-temphumidity-and-distance-using/editel

#include<LiquidCrystal.h>
LiquidCrystal mylcd(2,3,4,5,6,7);//(RS,EN,D4,D5,D6,D7)
//Initializations for temperature and humidity sensors
int temppin=0;
int humpin=1;
float temp,hum; 
//Initializations for Ultrasonic Sensor
int trig=9;
int echo=8;
float duration,distance;
int smokeSensor = A0;

void setup() {
  pinMode(trig,OUTPUT);//Initialize Triggerpin as Output
  pinMode(echo,INPUT);//Initialize Echo pin as Input
  mylcd.begin(16,2);//Initialize the lcd (16 colums and 2 rows)
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(5); 
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.0343)/2;
  
  temp = analogRead(temppin);        
  temp = temp * 0.48828125; 
  hum=analogRead(humpin);
  hum=(hum/1023)*100;
  
  
  {
    
    mylcd.setCursor(0,0);//The cursor is set at row 0 column 0
    mylcd.print("TEM:");//Printing the character TEM: in the lcd
    mylcd.setCursor(4,0);//column 4 and row 0
    mylcd.print(String(temp));//Printing the value of temp in lcd
    mylcd.setCursor(8,0);
    mylcd.print("HUM:");
    mylcd.setCursor(12,0);
    mylcd.print(String(hum));
    mylcd.setCursor(0,1);
    mylcd.print("DIST:");
    mylcd.setCursor(6,1);
    mylcd.print(String(distance));
    if(distance < 200) 
    {
      mylcd.clear();
      mylcd.print("Distance is so close...Please push break");
    }
    else if( (temp < 13) || (hum > 60) )
    {
      mylcd.clear();
      mylcd.print("Not Safe For driving due to tempreature");
    }
    else
    {
      	mylcd.print("Safe Driving");
    }
  }  
  
 
 
}