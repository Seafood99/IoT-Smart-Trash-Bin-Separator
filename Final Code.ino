// Code Explanation
// The code controls the behavior of the smart trash bin based on sensor readings:

// Distance Measurement: The HC-SR04 sensor measures the distance of the object. If the object is within 5 cm, the system proceeds to identify its material.
// Material Detection: The capacitive proximity sensor detects whether the object is metallic or non-metallic. If metallic, the servo motor turns to 0° to direct the object to the inorganic bin. If non-metallic, the servo turns to 180° to direct it to the organic bin.
// Display Output: The LCD displays the type of waste (organic or inorganic) and the direction of the separator. This information is also printed to the Serial Monitor for debugging purposes.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Pin declaration
const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 9;
const int proximityPin = 10;

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27 and 16x2 display

void setup() {
  // Pin initialization
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(proximityPin, INPUT);
  
  // LCD Initialization
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Servo Initialization
  myServo.attach(servoPin);
  myServo.write(90); // Servo position in the center

  // Serial Monitor Initialization
  Serial.begin(9600);
}

void loop() {
  // Calculating distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  
  // Read value from proximity sensor
  int proximityValue = digitalRead(proximityPin);
  
  if (distance <= 5) {
    if (proximityValue == HIGH) { // Inorganics (logam)
      myServo.write(0); // Servo moves to the left
      lcd.clear();
      lcd.print("inorganics");
      lcd.setCursor(0, 1);
      lcd.print("Left Separator");
      
      // Display on Serial Monitor
      Serial.println("This is garbage inorganics");
      Serial.println("The separator moves to the left");
    } else { // Organic (non-metallic)
      myServo.write(180); // Servo moves to the right`
      lcd.clear();
      lcd.print("Organik");
      lcd.setCursor(0, 1);
      lcd.print("Right Separator");
      
      // Display on Serial Monitor
      Serial.println("This is organic waste");
      Serial.println("The separator moves to the right");
    }
  } else {
    myServo.write(90); // Servo returns to center position
  }
  
  delay(1000); // Delay 1 second before the next loop
}
