# ESP32 PWM Control (Latest LEDC API)

![ESP32](https://img.shields.io/badge/Board-ESP32-blue)
![Arduino](https://img.shields.io/badge/Arduino_Core-3.x-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![License](https://img.shields.io/badge/License-MIT-red)

A simple example demonstrating **PWM (Pulse Width Modulation)** on the **ESP32** using the **latest Arduino ESP32 Core 3.x LEDC API**.

Unlike older versions, the new API **automatically manages PWM channels**, making the code cleaner and easier to understand.

---

# Features

- ✅ Uses the latest `ledcAttach()` API
- ✅ Automatic PWM channel allocation
- ✅ No manual channel management
- ✅ 5 kHz PWM Frequency
- ✅ 8-bit PWM Resolution
- ✅ Beginner Friendly
- ✅ Compatible with ESP32 Arduino Core 3.x
- ✅ Easy to modify for LEDs, motors, buzzers, RGB LEDs, fans, and more

---

# Hardware Required

- ESP32 Development Board
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

---

# Circuit Diagram

```text
ESP32 GPIO12 ---- 220Ω ----|>|---- GND
                           LED
```

> You can replace **GPIO12** with any PWM-capable GPIO supported by your ESP32 board.

---

# Source Code

```cpp
// Define constants
const int ledPin = 12;
const int freq = 5000;
const int resolution = 8;

void setup()
{
    // Attach PWM to GPIO12
    ledcAttach(ledPin, freq, resolution);
}

void loop()
{
    // 50% Duty Cycle
    ledcWrite(ledPin, 128);
}
```

---

# PWM Parameters

| Parameter | Value |
|-----------|------:|
| GPIO | 12 |
| Frequency | 5000 Hz |
| Resolution | 8-bit |
| Duty Cycle | 128 |

---

# Duty Cycle Values

For **8-bit PWM**, the duty cycle ranges from **0 to 255**.

| Duty | Output |
|------|---------|
| 0 | OFF |
| 64 | 25% Brightness |
| 128 | 50% Brightness |
| 192 | 75% Brightness |
| 255 | 100% Brightness |

Example:

```cpp
ledcWrite(ledPin, 0);     // OFF

ledcWrite(ledPin, 64);    // 25%

ledcWrite(ledPin, 128);   // 50%

ledcWrite(ledPin, 192);   // 75%

ledcWrite(ledPin, 255);   // 100%
```

---

# PWM Formula

```
Duty Cycle Range = (2^Resolution) - 1
```

Example for **8-bit**

```
2^8 - 1 = 255
```

---

# Old API vs New API

Starting from **Arduino ESP32 Core 3.x**, Espressif simplified the LEDC API.

## Old API (ESP32 Arduino Core 2.x)

In previous versions, users had to manually create and manage PWM channels.

```cpp
const int ledPin = 12;
const int channel = 0;
const int freq = 5000;
const int resolution = 8;

void setup()
{
    ledcSetup(channel, freq, resolution);
    ledcAttachPin(ledPin, channel);
}

void loop()
{
    ledcWrite(channel, 128);
}
```

---

## New API (ESP32 Arduino Core 3.x)

Now the PWM channel is automatically created internally.

```cpp
const int ledPin = 12;
const int freq = 5000;
const int resolution = 8;

void setup()
{
    ledcAttach(ledPin, freq, resolution);
}

void loop()
{
    ledcWrite(ledPin, 128);
}
```

---

# API Comparison

| Feature | Old API (Core 2.x) | New API (Core 3.x) |
|----------|--------------------|--------------------|
| Configure PWM | `ledcSetup()` | Automatic |
| Attach GPIO | `ledcAttachPin()` | `ledcAttach()` |
| PWM Channel | User Defined | Automatically Assigned |
| Write PWM | `ledcWrite(channel, duty)` | `ledcWrite(pin, duty)` |
| Setup Functions | 2 | 1 |
| Channel Management | Manual | Automatic |
| Beginner Friendly | ❌ | ✅ |
| Recommended | Legacy | Latest |

---

# Migration Guide

If you're upgrading from **Arduino ESP32 Core 2.x** to **Core 3.x**, replace the old functions with the new ones.

| Old Function | New Function |
|--------------|--------------|
| `ledcSetup()` | Removed |
| `ledcAttachPin()` | `ledcAttach()` |
| `ledcWrite(channel, duty)` | `ledcWrite(pin, duty)` |

### Old

```cpp
ledcSetup(channel, freq, resolution);
ledcAttachPin(pin, channel);
ledcWrite(channel, duty);
```

### New

```cpp
ledcAttach(pin, freq, resolution);
ledcWrite(pin, duty);
```

> **Important:** `ledcWrite()` now uses the **GPIO pin** instead of the **PWM channel**.

---

# Why Was the API Changed?

The new LEDC API provides several improvements:

- 🚀 Less code to write
- 🚀 Automatic PWM channel allocation
- 🚀 Cleaner syntax
- 🚀 Easier for beginners
- 🚀 Fewer channel conflicts
- 🚀 Better support for future ESP32 chips
- 🚀 More maintainable code

---

# Applications

- LED Brightness Control
- RGB LED Control
- DC Motor Speed Control
- Fan Speed Control
- Servo Motor Signal Generation
- Audio Tone Generation
- Robotics
- Embedded Systems
- IoT Projects
- Automation Systems

---

# Compatible Boards

- ESP32 DevKit V1
- ESP32-WROOM-32
- ESP32-WROVER
- ESP32-S2
- ESP32-S3
- ESP32-C3
- ESP32-C6

---

# Software Requirements

- Arduino IDE 2.x or later
- ESP32 Arduino Core 3.x or later

---

# Project Structure

```text
ESP32_PWM_Control/
│
├── ESP32_PWM_Control.ino
├── README.md
└── LICENSE
```

---

# Author

**Surya Mani Bajpai**

Electronics Engineer • Embedded Systems • IoT • Robotics • PCB Design



GitHub:
https://github.com/Surya-8948

---

# License

This project is licensed under the **MIT License**.

---

## ⭐ Support

If you found this project helpful:

⭐ Star this repository

🍴 Fork it

📢 Share it with others

Happy Coding! 🚀
