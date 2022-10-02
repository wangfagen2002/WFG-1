#include"FastLED.h"
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 6
#define ENB 7
#define NUM_LEDS 25
#define DATA_PIN 13
#define LED_TYPE WS2812
#define COLOR_ORDER RGB
uint8_t max_bright = 255;
CRGB leds[NUM_LEDS];

int m = 200;
void LED()
{
    fill_rainbow(leds,25,20,10);
    FastLED.show();
}
void colos()
{
  fill_solid(leds,25,CRGB::Black);
  FastLED.show();
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("蓝牙连接正常");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER> (leds, NUM_LEDS);
  FastLED.setBrightness(max_bright);
}

void loop() {
  while ( Serial.available()) {
    char c = Serial.read();
    if (c == 'w') {
      
      Serial.println("BT is ready!");
      Serial.write("gogo");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, m);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      analogWrite(ENB, m);
    }
    if (c == 's') {
      Serial.println("BT is ready!");
      Serial.write("downdown");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, m);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      analogWrite(ENB, m );
    }
    if (c == 'a') {
      Serial.println("BT is ready!");
      Serial.write("lift");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, m);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      analogWrite(ENB, m);
    }
    if (c == 'd') {
      Serial.println("BT is ready!");
      Serial.write("right");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, m);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      analogWrite(ENB, m);
    }
    if (c == 't') {
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }
    if(c=='k'){
      LED();
    }
     if(c=='g'){
      colos();
    }
  }
}
