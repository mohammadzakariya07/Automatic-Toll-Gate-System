#include <Servo.h>
#include <LiquidCrystal.h>

Servo gateServo;

// LCD pin configuration
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Pin definitions
const int irSensorPin = 8;
const int servoPin = 9;
const int buzzerPin = 10;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0); // Gate closed

  lcd.begin(16, 2);
  lcd.print("Toll Gate Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int vehicleDetected = digitalRead(irSensorPin);

  if (vehicleDetected == LOW) { // IR sensor active LOW
    lcd.clear();
    lcd.print("Vehicle Detected");
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);

    gateServo.write(90); // Open gate
    lcd.setCursor(0, 1);
    lcd.print("Gate Open");
    delay(3000);

    gateServo.write(0); // Close gate
    lcd.clear();
    lcd.print("Gate Closed");
    delay(2000);
    lcd.clear();
  }
}
