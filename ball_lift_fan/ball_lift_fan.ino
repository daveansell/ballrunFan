#define SPEED_PIN A7
#define SPEED_GND_PIN A2 
#define SWITCH_PIN A5
#define SWITCH_GND_PIN A4
#define SWITCH_LED_PIN A3
#define FAN_PIN 3
#define LED_PIN 13
#define FAN_5V 2
#define ON 1
#define OFF 0


#define TIMEOUT 10000

#include "CamSwitch.h" 

CamSwitch button(SWITCH_PIN, CamSwitch::LED_LATCH, SWITCH_LED_PIN,  TIMEOUT, 5, 1, 0);

void setup() {
  // put your setup code here, to run once:
  pinMode(SPEED_PIN, INPUT);
  pinMode(SPEED_GND_PIN, OUTPUT);
  digitalWrite(SPEED_GND_PIN, 0);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(SWITCH_GND_PIN, OUTPUT);
  digitalWrite(SWITCH_GND_PIN, 0);
  pinMode(SWITCH_LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, OFF);
  
  pinMode(FAN_5V, OUTPUT);
  digitalWrite(FAN_5V, ON);
      pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, OFF);

  pinMode(SWITCH_LED_PIN, OUTPUT);
  digitalWrite(SWITCH_LED_PIN, 1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int speedVal=analogRead(SPEED_PIN);
  
  int delayTime = 16 * speedVal;
  Serial.println(delayTime);
  if(button.get()){
    
    digitalWrite(FAN_PIN, ON);
    digitalWrite(LED_PIN, ON);

    delayMicroseconds(delayTime);
    if(delayTime<16360){
      digitalWrite(FAN_PIN, OFF);
      digitalWrite(LED_PIN, OFF);
      delayMicroseconds(16383-delayTime);
    }
    
  }else{
    digitalWrite(FAN_PIN, OFF);
    digitalWrite(LED_PIN, OFF);

  }
}
