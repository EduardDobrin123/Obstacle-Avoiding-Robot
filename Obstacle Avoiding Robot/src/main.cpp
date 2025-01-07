#include <Servo.h>
#include <Arduino.h>

// Servo and sensor pin definitions
Servo Myservo;
#define trigPin 9           // Trig Pin Of HC-SR04
#define echoPin 8           // Echo Pin Of HC-SR04
#define MLa 3               // Left motor 1st pin
#define MLb 5               // Left motor 2nd pin
#define MRa 6               // Right motor 1st pin
#define MRb 11               // Right motor 2nd pin

// Variables
long duration, distance;
const int safeDistance = 25;  // Safe distance to avoid obstacles (cm)
const int minDistance = 5;    // Minimum detectable distance (cm)

const int motorSpeed = 140;  

// Function declarations
long getDistance();
void moveForward();
void stopMotors();
void avoidObstacle();
void moveBackward();
void turnLeft();
void turnRight();
void stabilizeDistance();

void setup() {
  Serial.begin(9600);

  // Motor pins setup
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  // Sensor pins setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach servo
  Myservo.attach(10);
  Myservo.write(90); // Initial position
}

void loop() {
  // Measure and stabilize distance
  distance = getDistance();
  stabilizeDistance();

  Serial.println(distance);

  if (distance > safeDistance) {  // No obstacle detected
    moveForward();
  } else if (distance <= safeDistance && distance > minDistance) {  // Obstacle detected
    avoidObstacle();
  } else {  // Very close to obstacle or invalid reading
    stopMotors();
  }
}

// Function to measure distance using ultrasonic sensor
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);  // Timeout at 30ms (approx 500cm range)
  if (duration == 0) return -1;             // No echo received
  return duration / 58.2;                   // Convert to cm
}

// Function to stabilize distance measurement by averaging
void stabilizeDistance() {
  const int numSamples = 5;
  long totalDistance = 0;
  int validSamples = 0;

  for (int i = 0; i < numSamples; i++) {
    long sample = getDistance();
    if (sample > 0) {  // Ignore invalid readings
      totalDistance += sample;
      validSamples++;
    }
    delay(10);  // Small delay between readings
  }

  if (validSamples > 0) {
    distance = totalDistance / validSamples;
  } else {
    distance = -1;  // No valid readings
  }
}

// Function to move forward
void moveForward() {
  Myservo.write(90);  // Center servo
  analogWrite(MRb, motorSpeed);  
  analogWrite(MRa, 0);   
  analogWrite(MLb, motorSpeed);  
  analogWrite(MLa, 0);   
}

// Function to stop all motors
void stopMotors() {
  analogWrite(MRb, 0);  
  analogWrite(MRa, 0);  
  analogWrite(MLb, 0);  
  analogWrite(MLa, 0);  
}

// Function to avoid obstacles
void avoidObstacle() {
  stopMotors();  // Stop before scanning
  delay(100);

  // Scan left and right
  int leftDistance, rightDistance;
  Myservo.write(0);  // Look left
  delay(500);
  leftDistance = getDistance();

  Myservo.write(180);  // Look right
  delay(500);
  rightDistance = getDistance();

  Myservo.write(90);  // Reset to center
  delay(500);

  // Decide direction based on scanned distances
  if (leftDistance > rightDistance) {
    turnLeft();
  } else {
    turnRight();
  }

  // Move backward slightly before turning
  moveBackward();
  delay(300);
}

// Function to move backward
void moveBackward() {
  analogWrite(MRb, 0);   
  analogWrite(MRa, motorSpeed);  
  analogWrite(MLb, 0);   
  analogWrite(MLa, motorSpeed);  
}

// Function to turn left
void turnLeft() {
  analogWrite(MRb, motorSpeed);  
  analogWrite(MRa, 0);  
  analogWrite(MLb, 0);  
  analogWrite(MLa, 0);  
  delay(500);  
}

// Function to turn right
void turnRight() {
  analogWrite(MRb, 0);  
  analogWrite(MRa, 0);  
  analogWrite(MLb, motorSpeed);  
  analogWrite(MLa, 0);  
  delay(500);  
}
