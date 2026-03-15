/*
  ---------------------------------------------------------
  Project : DIY Auto Target Missile Launcher
  Channel : AmithLabs
  Author  : Amith Wijekoon
  ---------------------------------------------------------

  This Arduino project demonstrates a simple automatic
  targeting system inspired by radar-based defense systems.

  The ultrasonic sensor scans the environment using a servo
  motor (radar servo). When an object is detected within the
  defined target distance, the launcher rotates, raises the
  arm, and activates an ignition module.

  This project is intended for educational and demonstration
  purposes related to Arduino, robotics, and automation.

  ---------------------------------------------------------
  Hardware Connections
  ---------------------------------------------------------

  Ultrasonic Sensor
    TRIG -> Pin 3
    ECHO -> Pin 2

  Servos
    Rotary Servo      -> Pin 9
    Up/Down Servo     -> Pin 10
    Radar Servo       -> Pin 11

  Ignition Output
    Ignition Coil -> Pin 4

  ---------------------------------------------------------
*/

#include <Servo.h>

// Servo objects
Servo rotaryServo;
Servo armServo;
Servo radarServo;

// Pin definitions
#define TRIG_PIN 3
#define ECHO_PIN 2
#define IGNITION_PIN 4

// System parameters
#define TARGET_DISTANCE 50   // cm
#define FIRE_TIME 500        // ignition time in milliseconds

// Initial positions
#define ROTARY_INITIAL 190
#define ARM_INITIAL 0
#define RADAR_INITIAL 0

// Fire position
#define ARM_FIRE_POS 60

// Radar scan range
#define RADAR_MIN 0
#define RADAR_MAX 180

// ---------------------------------------------------------
// Function: Read ultrasonic distance with filtering
// ---------------------------------------------------------

float readDistanceFiltered()
{
  float readings[5];

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(5);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    readings[i] = duration * 0.034 / 2;

    delay(20);
  }

  // Find highest and lowest values
  float maxVal = readings[0];
  float minVal = readings[0];
  float sum = 0;

  for (int i = 0; i < 5; i++)
  {
    if (readings[i] > maxVal) maxVal = readings[i];
    if (readings[i] < minVal) minVal = readings[i];
    sum += readings[i];
  }

  // Remove highest and lowest
  sum = sum - maxVal - minVal;

  // Average remaining 3 values
  return sum / 3.0;
}

// ---------------------------------------------------------
// Arduino Setup
// ---------------------------------------------------------

void setup()
{
  // Attach servos
  rotaryServo.attach(9);
  armServo.attach(10);
  radarServo.attach(11);

  // Pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IGNITION_PIN, OUTPUT);

  digitalWrite(IGNITION_PIN, LOW);

  // Move servos to initial positions
  rotaryServo.write(ROTARY_INITIAL);
  armServo.write(ARM_INITIAL);
  radarServo.write(RADAR_INITIAL);

  // Wait for system stabilization
  delay(3000);
}

// ---------------------------------------------------------
// Main Program (runs once)
// ---------------------------------------------------------

void loop()
{

  // Radar scanning
  for (int angle = RADAR_MIN; angle <= RADAR_MAX; angle += 3)
  {

    radarServo.write(angle);
    delay(60);

    float distance = readDistanceFiltered();

    // Target detected
    if (distance > 0 && distance <= TARGET_DISTANCE)
    {

      // Stop scanning
      radarServo.write(angle);

      // Rotate launcher to target direction
      rotaryServo.write(angle);

      delay(500);

      // Raise launcher arm
      armServo.write(ARM_FIRE_POS);

      delay(1000);

      // Fire ignition
      digitalWrite(IGNITION_PIN, HIGH);
      delay(FIRE_TIME);
      digitalWrite(IGNITION_PIN, LOW);

      // End program
      while (true);
    }
  }

  // If no target detected, stop program
  while (true);
}