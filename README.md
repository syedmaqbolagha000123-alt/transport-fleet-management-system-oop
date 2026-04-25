# 🚛 Transport Fleet Management System (C++ OOP Project)

## 📌 Overview
This project is a console-based Transport Fleet Management System developed in C++. It simulates real-world logistics operations by managing vehicles, drivers, routes, and shipments using Object-Oriented Programming (OOP) principles.

---

## 🎯 Purpose
The goal of this project is to apply core OOP concepts in a real-world system:
- Encapsulation  
- Inheritance  
- Abstraction  
- Polymorphism  
- Dynamic Memory Allocation  

---

## 🧱 Project Structure

include/   → Header files (.h)  
src/       → Source files (.cpp)  
main.cpp   → Main program entry point  

---

## 🚗 Class Hierarchy

Vehicle (Abstract Base Class)
Vehicle
├── LandVehicle
│ ├── Truck
│ └── Van
├── AirVehicle
│ ├── CargoPlane
│ └── Helicopter

Person (Abstract Base Class)
└── Driver

Other Classes:
- Route
- Shipment
- Fleet (managed using pointers)

---

## 🧠 OOP Concepts Used

### Encapsulation
Private data members such as vehicle plate, model, driver license, etc.

### Inheritance
- Multi-level: Vehicle → LandVehicle → Truck  
- Hierarchical: Vehicle → multiple derived classes  
- Single: Person → Driver  

### Abstraction
Pure virtual functions:
- calcCost()
- getType()

### Polymorphism
- Function overriding in all vehicle types  
- Function overloading for search  
- Operator overloading: ==, >, <<  

### Dynamic Memory Allocation
Uses:
- Vehicle** fleet  
- Driver** drivers  
Managed using new and delete.

---

## ⚙️ Features
- Add vehicles  
- Add drivers  
- Create routes  
- Create shipments  
- Dispatch shipments  
- Calculate freight cost  
- Compare vehicles  
- Search vehicles  

---

## ▶️ How to Run

Using g++:
g++ main.cpp -o fleet
./fleet

Or open in any C++ IDE and run main.cpp.

---

## 🧪 Sample Data
Preloaded:
- Trucks
- Vans
- Cargo Plane
- Helicopter
- Drivers
- Routes

---

## 🎓 Learning Outcomes
- Strong understanding of OOP  
- Real-world system design  
- Memory management using pointers  
- Modular programming  

---

## 👨‍💻 Author
Semester project for Object-Oriented Programming (OOP)
