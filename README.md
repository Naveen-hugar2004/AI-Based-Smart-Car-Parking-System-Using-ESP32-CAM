# AI-Based-Smart-Car-Parking-System-Using-ESP32-CAM

## 📌 Project Overview

The **AI Based Smart Car Parking System using ESP32-CAM** is a smart parking management solution designed to make parking easier, faster, and more efficient.

The system uses an **ESP32-CAM with a built-in camera** to monitor parking spaces and capture vehicle number plates. IR sensors are used to detect parking-space availability, while a servo motor can control the parking entrance barrier. The system provides real-time information about available parking spaces.

## 🎯 Objectives

* Detect and identify vehicles using the ESP32-CAM.
* Monitor parking spaces in real time.
* Automatically determine whether parking spaces are **occupied or free**.
* Capture vehicle number plates using the camera.
* Display parking availability to users.
* Reduce manual intervention in parking management.

## ⚙️ How It Works

1. The system starts in its default state.
2. The **IR sensor module** senses the parking area.
3. The LCD displays the parking availability.
4. If parking spaces are available, the system displays **"Parking Lot is Available"**.
5. If no spaces are available, it displays **"No Available Parking Lot"**.
6. The **ESP32-CAM scans and saves the vehicle number plate**.

## 🔧 Components Used

* ESP32-CAM
* IR Sensor Module
* Servo Motor
* LCD Display
* Breadboard
* Jumper Wires

## 🧠 Technologies Used

* Embedded C / Arduino Programming
* ESP32-CAM
* Computer Vision
* Automatic Number Plate Recognition (ANPR)
* IoT
* IR-based vehicle detection

## ✨ Features

* 📷 Vehicle detection using ESP32-CAM
* 🔢 Number plate capture
* 🅿️ Parking-slot availability detection
* 📺 LCD-based status display
* 🚧 Automatic parking barrier control
* ⚡ Real-time parking monitoring
* 💰 Cost-effective implementation

## ✅ Benefits

* Saves time for drivers
* Reduces fuel consumption
* Reduces manual intervention
* Provides real-time parking information
* Cost-effective and scalable
* Improves user convenience and satisfaction

## 🏢 Applications

The system can be used in:

* Shopping malls
* Large commercial complexes
* Smart parking facilities
* Urban parking areas
* Private parking lots

## 📊 System Flow

```text
              START
                │
                ▼
          LCD Display
                │
                ▼
       IR Sensor Sensing
                │
        ┌───────┴────────┐
        │                │
        ▼                ▼
 Parking Available   No Parking
        │                │
        ▼                ▼
   ESP32-CAM scans    Display Status
   vehicle number
        │
        ▼
    Save Number Plate
        │
        ▼
              END
```

## 📚 Literature Background

Previous smart parking systems have explored ESP32-CAM with IoT, AI-based image processing, YOLO/CNN-based vehicle detection, and real-time communication technologies such as MQTT.

## 🚀 Future Improvements

* Add a mobile/web application for parking availability.
* Store vehicle details in a cloud database.
* Add multiple parking slots with individual sensors.
* Improve number plate recognition accuracy.
* Add online parking reservation.
* Integrate payment functionality.
* Provide live parking availability through IoT.

## 👨‍💻 Project Team

**Department of Electronics and Communication Engineering**

* Vikas K
* Naveen H
* Rahul K

**Guide:** Prof. Ms. Ratnaprabha Shiroor

**College:** SKSVMA Charitable Trust, Smt Kamala & Sri Venkappa M Agadi College of Engineering & Technology, Laxmeshwar.

## 📖 References

1. Smart Parking System using ESP32-CAM and IoT (2022)
2. AI-Powered Parking Management with ESP32-CAM (2022)
3. Real-Time Vehicle Detection and Parking System using ESP32-CAM (2023)

## 🏁 Conclusion

The **AI Based Smart Car Parking System using ESP32-CAM** provides a modern approach to parking management by combining **AI, IoT, computer vision, and embedded systems**. It helps monitor parking spaces in real time and captures vehicle number plates, making parking more efficient and convenient.

---

⭐ **If you found this project useful, consider giving the repository a star!**
