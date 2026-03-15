# Arduino Auto Target Missile Launcher

[![Watch the video](https://img.youtube.com/vi/3qiN1pMbKuA/0.jpg)](https://youtu.be/3qiN1pMbKuA)

📺 **Watch the Full Build Video on YouTube**
https://youtu.be/3qiN1pMbKuA

---

## Project Overview

This project demonstrates a **DIY Arduino Auto Target Missile Launcher** inspired by radar-based defense systems.
An ultrasonic sensor mounted on a rotating servo scans the surrounding area like a radar system. When an object is detected within the defined distance, the launcher automatically rotates toward the target, raises the launcher arm, and activates the ignition module.

This project is designed for **educational and demonstration purposes** related to Arduino programming, robotics, automation, and sensor systems.

The full build process is available on the **AmithLabs YouTube channel**.

---

## Main Features

* Ultrasonic radar scanning system
* Automatic target detection
* Servo-controlled launcher rotation
* Servo-controlled launcher elevation
* Ignition activation system
* Distance filtering for stable detection

---

## Hardware Components

* Arduino Uno
* Ultrasonic Sensor (HC-SR04)
* 3x Servo Motors
* Ignition Coil / High Voltage Igniter Module
* Relay Module
* Power Supply
* DIY Launcher Mechanism
* Connecting Wires

---

## Pin Configuration

| Component         | Arduino Pin |
| ----------------- | ----------- |
| Ultrasonic Echo   | 2           |
| Ultrasonic Trig   | 3           |
| Ignition Output   | 4           |
| Rotary Servo      | 9           |
| Arm Up/Down Servo | 10          |
| Radar Servo       | 11          |

---

## System Operation

1. System powers on and moves all servos to their **initial positions**.
2. The radar servo rotates the ultrasonic sensor from **0° to 180°** scanning the environment.
3. Distance readings are filtered to remove noise.
4. If an object is detected within **50 cm**, the system identifies it as a target.
5. The launcher rotates toward the detected direction.
6. The launcher arm moves upward to the firing position.
7. The ignition output activates briefly to launch the projectile.
8. The program stops after firing.

---

## Arduino Code

The complete Arduino program is included in this repository:

```
Missile_Launch_Full.ino
```

This code controls:

* Radar scanning
* Target detection
* Servo movement
* Ignition activation

---

## Project Images

```
Missile Launcher.jpg
```

---

## YouTube Channel

This project was created for the **AmithLabs** YouTube channel.

Subscribe for more DIY electronics, robotics, and automation projects.

---

## Disclaimer

This project is created strictly for **educational and experimental purposes only**.
It should be used responsibly and safely. The creator is not responsible for any misuse of the project.

---

## Author

**Amith Wijekoon**
Automation & Electrical Engineering Specialist
Creator of the **AmithLabs** YouTube Channel
