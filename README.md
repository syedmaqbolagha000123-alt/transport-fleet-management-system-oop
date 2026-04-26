# 🚛 Transport Fleet Management System

A console-based C++ application for managing a logistics company's fleet of vehicles, drivers, routes, and shipments. This project demonstrates core Object-Oriented Programming concepts including encapsulation, inheritance, abstraction, and polymorphism, in addition to dynamic memory allocation and file handling.

---

## 👥 Group Members

| Name | Student ID |
|------|------------|
| Syed Mohammad Mahboor Hussain | 25K-0749 |
| Syed Maqbool Ahmed | 25K-0812 |

---

## 📋 Project Description

FAST Logistics Fleet Management System allows a logistics company to:

- Maintain a fleet of land vehicles (Trucks, Vans) and air vehicles (Cargo Planes, Helicopters)
- Register and manage drivers
- Define delivery routes between cities
- Create and dispatch shipments with automatic freight cost calculation

The freight cost is calculated based on vehicle type, cargo weight, distance, and applicable surcharges, simulating a real-world logistics pricing model.

---

## 🗂️ Project Structure

```
Header and Implementation Files        <-- separate file for each class 
main.cpp                               <-- combines functions from all classes into a menu-driven interface
.txt files                             <-- Used to store data to and load data from the secondary storage
```

### Class Hierarchy

```
Vehicle          (abstract)
├── LandVehicle  (abstract)
│   ├── Truck
│   └── Van
└── AirVehicle   (abstract)
    ├── CargoPlane
    └── Helicopter

Person           (abstract)
└── Driver

Route            (standalone)
Shipment         (standalone)
```

---

## ✅ Use Cases

### 1. Booking a Cargo Shipment
User selects a vehicle, assigns an available driver, picks a route, and enters the cargo weight. The system validates that the cargo fits the vehicle and automatically calculates the freight cost before dispatching.

### 2. Choosing the Right Vehicle for a Job
The user uses the **Compare Vehicles** option to check which vehicle has a higher cargo capacity. This makes use of the overloaded `>` operator. Program also allows user to use the **Freight Cost Calculator** to compare costs across different vehicle types for the same route, helping make a cost-effective decision.

### 3. Managing Driver Availability
Before assigning a driver, user can view the driver list to see who is marked **Free** and who is marked **On Duty**, preventing the same driver from being double-booked on two simultaneous shipments.

### 4. Adding a New Vehicle in the Fleet
When the company acquires a new vehicle, the user adds it through the **Add Vehicle** menu, entering all relevant details (permit number, capacity, airport code, rotor diameter, etc.) so it is immediately available for future shipments.

### 5. Defining Routes for New Destinations
Program allows the company to expand to serve a new city. The user can add a new route with the origin, destination, and distance. That route then becomes available for any future shipment, whether a short land delivery or a long international air cargo run.

### 6. Viewing / Auditing All Active Shipments
At the end of the day, user can select **View All Shipments** to get a complete list of every shipment; vehicle assigned, driver, route, cargo weight, dispatch status, and the freight cost billed to the client.

---

## ⚙️ Concepts Demonstrated

| Concept | Implementation |
|--------|-------|
| **Encapsulation** | Private attributes with getters/setters in all classes |
| **Multi-level Inheritance** | `Vehicle → LandVehicle → Truck` (3 levels) |
| **Hierarchical Inheritance** | `LandVehicle → {Truck, Van}` and `AirVehicle → {CargoPlane, Helicopter}` |
| **Abstraction** | Pure virtual `calcCost()`, `getType()` in `Vehicle`; `getRole()`, `display()` in `Person` |
| **Function Overriding** | Each vehicle category overrides `calcCost()`, `getType()`, and `display()` |
| **Function Overloading** | `showVehicle()` defined twice — once with `int` index, once with `string` plate |
| **Operator Overloading** | `operator==`, `operator>`, `operator<<` on `Vehicle`; `operator<<` on `Route` |
| **DMA** | `new`/`delete` used for all `Vehicle*`, `Driver*`, `Route*`, `Shipment*` arrays |
| **File Handling** | Vehicles stored in `vehicles.txt`, Routes in `routes.txt`, and Drivers in `drivers.txt` |

---

## 🔧 How to Compile

### Requirements
- A newer C++ compiler , preferably g++ (clang++ or MSVC can also work)
- A terminal / command prompt (VSCode's terminal is preferred)


### Procedure:
- Download the full ```Complete_Project_Code``` folder, and navigate to the folder on terminal
- For g++, using VSCode's terminal, type and run:
```
g++ (dir *.cpp) -o FleetManager
```
- Compiler will compile all .cpp files into a .exe file labelled 'FleetManager.exe'

---

## ▶️ How to Run

On the terminal, navigate to directory where you compiled the program and run the following command:
```
./FleetManager
```
Alternatively, you can also run the .exe directly from Windows GUI.
The program starts immediately and loads data from text files if present.
### NOTE: For ease of use, this program pre-loads sample data (3 vehicles, 2 drivers, 2 routes) for the first launch so you can test all features right away without entering data manually.

---

## 📖 How to Use the System

When the program starts, the user is taken straight to the home screen:
```
  ========================================
   FAST LOGISTICS - FLEET MANAGEMENT
  ========================================
  Vehicles: 5  | Drivers: 3  | Routes: 3  | Shipments: 0
  ----------------------------------------
  Select and Option:
  [1] Vehicles
  [2] Drivers
  [3] Routes
  [4] Shipments
  [0] Exit
  Choice:
```

The process from there onwards is straight forward. Just select the option number of action you want to perform.

For example, to perform tasks related to ```Drivers```, type ```2``` and press ```Enter```.

Each option takes you to a separate menu page, with more options for the tasks to perform.

```Vehicles``` option, for example, will take the user to following menu page:
```
  -- Vehicles --
  [1] Add Vehicle
  [2] View All Vehicles
  [3] Search Vehicle
  [4] Compare Vehicles
  [5] Calculate Freight Cost
  [0] Go Back
  Choice:
```

User just has to choose the task to perform, and follow the given instructions.

For easier flow of program, it makes use of ```system("cls")``` function from ```<cstdlib.h>``` to clear previous outputs from screen, and ```system("pause")``` to wait for user input before continuing after performing a task.

This menu runs in loop until the user chooses to ```[0] Exit```.

Before closing, all the data of Vehicles, Drivers, and Routes in Fleet is stored into text file so it can be loaded the next time program is run.

---

## ⚠️ Assumptions & Limitations

- **No File Handling for Shipments** - although drivers, vehicles, and routes are kept in storage, the shipments are not. User will need to create new shipments each time program is run.
- **Fixed array size** - the maximum number of vehicles, drivers, routes, and shipments is capped at the value user enters at beginning. These values cannot be changed without altering manually from MAX.txt and restarting the program. MAX.txt stores the maximum capacity in following manner:
```<MAX VEHICLES> <MAX DRIVERS> <MAX ROUTES? <MAX SHIPMENTS>```
To change this data, just change the number corresponding to the required field.
- **No unassign / delete** - once a vehicle is added, a driver is marked On Duty or a shipment is dispatched, there is no option to reverse it.
- **Single driver per shipment** - each shipment supports only one assigned driver. Co-driver support is not implemented.
- **Distance is entered manually** - the system does not integrate with any mapping API. Route distances must be entered by the user.
- **Shipment cost uses full vehicle capacity as base** - the freight cost is first calculated assuming a full load, then scaled down by the actual load factor. This means a lightly loaded expensive vehicle may still appear costly.
