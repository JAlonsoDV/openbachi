#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

#define pinSD 10
#define reloj tmrpcm.play("reloj.wav");
#define Error tmrpcm.play("Error.wav");

TMRpcm tmrpcm;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;
int botpin = 8;
int g = 50;
int d = 7000;
int r = 3000;




void setup() {
  
    pinMode(botpin,OUTPUT);
    
    tmrpcm.quality(1);
    tmrpcm.volume(7);  
    tmrpcm.speakerPin = 9;
    Serial.begin(9600);
    
    
    if (!SD.begin(pinSD)) {
      Serial.println("Fallo en la targeta SD");
      return;
    }
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
    delay(2000);
    tmrpcm.play("jorge.wav");
    delay(1500);
}
    int pulseWidth(int angle){
    int pulse_wide, analog_value;
    pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
    Serial.println(analog_value);
    return analog_value;
  }

void loop() { 
  int estado_btn  = digitalRead(botpin);
  Serial.println(estado_btn);

  if (estado_btn == 1){
    
      Inicio();
      delay(1000);
      rnd();
  }
}
  
