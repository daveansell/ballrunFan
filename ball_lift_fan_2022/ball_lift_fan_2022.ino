#include <CapacitiveSensor.h>

#define MOSFET_GND 5
#define MOSFET_5V 6
#define MOSFET 7

#define LED_GND A0
#define LED 2
#define SW_SENSE 3
#define SW_DRIVE 4

#define SW_LEVEL 100
#define DEBOUNCE 200
#define FLASH_LEN 1000
#define RUN_TIME 60000
uint32_t lastTime = 0;
uint32_t lastFlash = 0;
uint32_t onTime =0;
uint8_t mode=0;
uint8_t swState=0;

CapacitiveSensor button(SW_DRIVE,SW_SENSE);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(MOSFET_5V, OUTPUT);
  digitalWrite(MOSFET_5V, 1);
  pinMode(MOSFET, OUTPUT);
  digitalWrite(MOSFET, 0);
  pinMode(LED_GND, OUTPUT);
  digitalWrite(LED_GND,1);
  pinMode(LED, OUTPUT);
  button.set_CS_Timeout_Millis(10);
  
}

void loop() {
  Serial.print(mode);
  Serial.print(" ");
  Serial.println(button.capacitiveSensor(20));
  // put your main code here, to run repeatedly:
  if(button.capacitiveSensor(20)>SW_LEVEL){
    if(millis()-lastTime>DEBOUNCE and swState==0){
      mode = !mode;
      if(mode){
        onTime=millis();
      }
    }
    swState=1;
      
  }else{
    swState=0;
  }
  if(mode==0){
    digitalWrite(MOSFET,0);
    if((millis()-lastFlash) > FLASH_LEN){
      digitalWrite(LED, !digitalRead(LED));
      digitalWrite(13, !digitalRead(13));
      lastFlash=millis();
    }
  }else{
    if((millis()-onTime)<RUN_TIME){
      digitalWrite(MOSFET,1);
      digitalWrite(LED,1);
    }else{
      digitalWrite(MOSFET,0);
    }
  }
}
