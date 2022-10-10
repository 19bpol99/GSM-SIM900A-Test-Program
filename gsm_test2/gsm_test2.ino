#include <SoftwareSerial.h>

SoftwareSerial SIM900A(8, 9);
int button = 7;
int state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SIM900A.begin(9600);
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(button, INPUT_PULLUP);
  state = digitalRead(button);
  if (state == LOW){
    message();
    Serial.println("Message sent.");
  }
}

void message(){
  SIM900A.println("AT+CMGF=1");
  delay(1000);
  SIM900A.print("AT+CMGS=\+63XXXXXXXXXX\"\r");  // change to recipient's mobile number
  delay(1000);
  SIM900A.println("Testing SIM900A");
  delay(1000);
  SIM900A.println((char)26);
  delay(1000);
}
