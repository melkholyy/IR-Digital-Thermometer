#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float to;
int Rled=7;
int Gled=8;
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distance;
int x;
void setup()
 {

pinMode(Rled, OUTPUT);
pinMode(Gled, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
  mlx.begin();
  delay(1000);

  

 }
 void loop()
 {
x = ultraSonic ();
if (x>=9 && x<=12)
{
to = 8 + mlx.readObjectTempC();
delay(1000);
if(to>=38)
digitalWrite(Gled,HIGH);
else if ( to<38)

digitalWrite(Rled,HIGH);
}

 else if (x>12 || x<9)
  { 
    to=0;
 digitalWrite(Gled,LOW);
 digitalWrite(Rled,LOW);

 }

 } 
 
int ultraSonic ()
 {digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.println(distance);
return distance;
}
