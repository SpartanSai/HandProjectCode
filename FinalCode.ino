#include <Servo.h>

Servo s1; //goes to port 9
//const int flexPin = A5; //pin A5 to read analog input
int pos;

#define FORCE_FORWARD A0 // the FSR and 10K pulldown are connected to A0
#define FORCE_BACKWARD A5 // the FSR and 10K pulldown are connected to A5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.attach(9);
  pos = 90;
  
  s1.write(pos);
  Serial.print("Start is: ");
  Serial.println(pos);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogF = analogRead(FORCE_FORWARD);
  analogF = analogRead(FORCE_FORWARD);
  int analogB = analogRead(FORCE_BACKWARD);
  analogB = analogRead(FORCE_BACKWARD);

  //value = analogRead(flexPin);         //Read and save analog value from flex sensor
  Serial.print("Position: ");
  Serial.print(pos, DEC); 
  
  //now all the sensors are inverted: start from 1023
  // if(analogB<1021 && pos<=160){
  //   s1.write(pos+20);
  //   pos += 20;
  //   Serial.println("MOVING IN");
    
  // }
  // if(analogF<1021 && pos>=20){
  //   Serial.println("PAUSE");
  //   delay(500);

  //   analogF = analogRead(FORCE_FORWARD);
  //   analogF = analogRead(FORCE_FORWARD);
  //   if(analogF<1021 && pos<=170){
  //     s1.write(pos-20);
  //     pos -= 20;
  //     Serial.println("MOVING OUT");
  //   }
  // }

  if(analogB<1021 && pos<=160){
    s1.write(pos+20);
    pos += 20;
    Serial.println("MOVING IN");
    
  }
  if(analogF<1021 && pos>=20){
    Serial.println("PAUSE");
    delay(500);

    analogF = analogRead(FORCE_FORWARD);
    analogF = analogRead(FORCE_FORWARD);
    if(analogF<1021 && pos<=170){
      s1.write(pos-20);
      pos -= 20;
      Serial.println("MOVING OUT");
    }
  }



  Serial.println();              //Print value
  Serial.print("Force_FORWARD reading = ");
  Serial.print(analogF); // print the raw analog reading
  Serial.print("Force_BACKWARD reading = ");
  Serial.print(analogB); // print the raw analog reading
  delay(500);
}
