#include <Arduino.h>

// Motor driver pins
#define IN1 5  // Motor A input 1 (D1)
#define IN2 4  // Motor A input 2 (D2)
#define IN3 0  // Motor B input 1 (D3)
#define IN4 2  // Motor B input 2 (D4)
#define ENA 14 // Motor A enable pin (D5, PWM)
#define ENB 12 // Motor B enable pin (D6, PWM)

int speed = 512; // PWM speed (0–1023, half speed for testing)

void forward();
void backward();
void leftTurn();
void rightTurn();
void stopMotors();

void setup() {
  // Set pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize stop
  stopMotors();
  Serial.begin(115200); // Initialize serial communication for debugging
  Serial.println("Motor Driver Test");
  delay(2000); // Wait for 2 second
  Serial.println("Starting Motor A forward and Motor B stopped...");
  delay(2000); // Wait for 2 seconds
}

void loop() {
  // Test sequence: Forward, Backward, Left, Right, Stop
  forward();
  delay(2000);
  stopMotors();
  delay(1000);
  backward();
  delay(2000);
  stopMotors();
  delay(1000);
  leftTurn();
  delay(1000);
  stopMotors();
  delay(1000);
  rightTurn();
  delay(1000);
  stopMotors();
  delay(1000);
}

// Move forward: Both motors forward
void forward() {
  Serial.println("Moving forward...");
  // Set motor A forward and motor B forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Move backward: Both motors backward
void backward() {
  Serial.println("Moving backward...");
  // Set motor A backward and motor B backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Turn left: Right motor forward, Left motor backward
void leftTurn() {
  Serial.println("Turning left...");
  // Set motor A backward and motor B forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Turn right: Left motor forward, Right motor backward
void rightTurn() {
  Serial.println("Turning right...");
  // Set motor A forward and motor B backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Stop: All motors off
void stopMotors() {
  Serial.println("Stopping motors...");
  // Set all motors off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
