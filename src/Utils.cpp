#include "Utils.h"
#include "Truck.h"
#include "Van.h"
#include "CargoPlane.h"
#include "Helicopter.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ================= Function Overloading =================

void showVehicle(Vehicle** fleet, int index, int total) {
    if (index < 0 || index >= total) {
        cout << "  Invalid index.\n";
        return;
    }
    fleet[index]->display();
}

void showVehicle(Vehicle** fleet, string plate, int total) {
    for (int i = 0; i < total; i++) {
        if (fleet[i]->getPlate() == plate) {
            fleet[i]->display();
            return;
        }
    }
    cout << "  Vehicle with plate '" << plate << "' not found.\n";
}

// ================= Helpers =================

void printLine() {
    cout << "  ----------------------------------------\n";
}

void printHeader(string title) {
    cout << "\n  ========================================\n";
    cout << "   " << title << "\n";
    cout << "  ========================================\n";
}

// ================= Vehicle Menu =================

void addVehicle(Vehicle** fleet, int& count, int maxSize) {
    if (count >= maxSize) {
        cout << "  Fleet is full!\n";
        return;
    }

    printHeader("ADD VEHICLE");
    cout << "  [1] Truck\n"
         << "  [2] Van\n"
         << "  [3] Cargo Plane\n"
         << "  [4] Helicopter\n"
         << "  Choice: ";
    int type; cin >> type;

    string plate, model;
    int year;
    double cap;

    cout << "  Plate          : "; cin >> plate;
    cout << "  Model          : "; cin >> model;
    cout << "  Year           : "; cin >> year;
    cout << "  Capacity (tons): "; cin >> cap;

    if (type == 1) {
        string permit; char heavy;
        cout << "  Permit No      : "; cin >> permit;
        cout << "  Heavy truck? (y/n): "; cin >> heavy;
        fleet[count++] = new Truck(plate, model, year, cap, permit,
                                   (heavy == 'y' || heavy == 'Y'));
        cout << "  [OK] Truck added to fleet.\n";

    } else if (type == 2) {
        string permit; char fridge;
        cout << "  Permit No      : "; cin >> permit;
        cout << "  Refrigerated? (y/n): "; cin >> fridge;
        fleet[count++] = new Van(plate, model, year, cap, permit,
                                 (fridge == 'y' || fridge == 'Y'));
        cout << "  [OK] Van added to fleet.\n";

    } else if (type == 3) {
        double altitude, range; int engines; string airport;
        cout << "  Home Airport   : "; cin >> airport;
        cout << "  Altitude (ft)  : "; cin >> altitude;
        cout << "  No. of Engines : "; cin >> engines;
        cout << "  Range (km)     : "; cin >> range;
        fleet[count++] = new CargoPlane(plate, model, year, cap,
                                        altitude, airport, engines, range);
        cout << "  [OK] Cargo Plane added to fleet.\n";

    } else if (type == 4) {
        double altitude, rotorDiam; char winch; string airport;
        cout << "  Home Airport   : "; cin >> airport;
        cout << "  Altitude (ft)  : "; cin >> altitude;
        cout << "  Rotor Diam (m) : "; cin >> rotorDiam;
        cout << "  Has Winch? (y/n): "; cin >> winch;
        fleet[count++] = new Helicopter(plate, model, year, cap,
                                        altitude, airport,
                                        (winch == 'y' || winch == 'Y'),
                                        rotorDiam);
        cout << "  [OK] Helicopter added to fleet.\n";

    } else {
        cout << "  Invalid type.\n";
    }
}

void viewAllVehicles(Vehicle** fleet, int count) {
    if (count == 0) {
        cout << "  No vehicles in fleet yet.\n";
        return;
    }
    printHeader("ALL VEHICLES");
    for (int i = 0; i < count; i++) {
        cout << "\n  [" << (i + 1) << "] " << *fleet[i] << "\n";
        printLine();
        fleet[i]->display();
    }
}

void searchVehicle(Vehicle** fleet, int count) {
    printHeader("SEARCH VEHICLE");
    cout << "  [1] Search by index\n"
         << "  [2] Search by plate\n"
         << "  Choice: ";
    int choice; cin >> choice;

    if (choice == 1) {
        cout << "  Index (1 to " << count << "): ";
        int idx; cin >> idx;
        showVehicle(fleet, idx - 1, count);

    } else if (choice == 2) {
        cout << "  Plate number: ";
        string plate; cin >> plate;
        showVehicle(fleet, plate, count);

    } else {
        cout << "  Invalid.\n";
    }
}

void compareVehicles(Vehicle** fleet, int count) {
    if (count < 2) {
        cout << "  Need at least 2 vehicles.\n";
        return;
    }

    printHeader("COMPARE VEHICLES");
    int a, b;
    cout << "  Vehicle A index: "; cin >> a;
    cout << "  Vehicle B index: "; cin >> b;

    if (a < 1 || a > count || b < 1 || b > count) {
        cout << "  Invalid index.\n";
        return;
    }

    Vehicle* va = fleet[a - 1];
    Vehicle* vb = fleet[b - 1];

    cout << "\n  A: " << *va << "\n";
    cout << "  B: " << *vb << "\n";
    cout << "  A > B? " << ((*va > *vb) ? "Yes" : "No") << "\n";
    cout << "  A == B? " << ((*va == *vb) ? "Yes" : "No") << "\n";
}

void calcFreightCost(Vehicle** fleet, int count) {
    if (count == 0) return;

    printHeader("FREIGHT COST");
    int idx;
    double dist;

    cout << "  Vehicle index: "; cin >> idx;
    cout << "  Distance: "; cin >> dist;

    double cost = fleet[idx - 1]->calcCost(dist);
    cout << "  Cost: Rs " << cost << "\n";
}

// ================= Driver =================

void addDriver(Driver** drivers, int& count, int maxSize) {
    if (count >= maxSize) return;

    string name, license;
    int age;

    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "License: "; cin >> license;

    drivers[count++] = new Driver(name, age, license);
}

void viewDrivers(Driver** drivers, int count) {
    for (int i = 0; i < count; i++) {
        drivers[i]->display();
    }
}

void assignDriver(Vehicle**, int,
                  Driver** drivers, int dCount) {
    int idx;
    cout << "Select driver: "; cin >> idx;
    if (idx >= 1 && idx <= dCount)
        drivers[idx - 1]->setOnDuty(true);
}

// ================= Routes =================

void addRoute(Route** routes, int& count, int maxSize) {
    if (count >= maxSize) return;

    string from, to;
    double dist;

    cin >> from >> to >> dist;
    routes[count++] = new Route(from, to, dist);
}

void viewRoutes(Route** routes, int count) {
    for (int i = 0; i < count; i++) {
        routes[i]->display();
    }
}

// ================= Shipment =================

void createShipment(Shipment** shipments, int& sCount, int maxSize,
                    Vehicle** fleet, int vCount,
                    Driver** drivers, int dCount,
                    Route** routes, int rCount) {

    if (sCount >= maxSize) return;

    int vi, di, ri;
    double cargo;

    cin >> vi >> di >> ri >> cargo;

    string sid = "SHP-00" + to_string(sCount + 1);

    shipments[sCount++] = new Shipment(
        sid, cargo,
        fleet[vi - 1],
        drivers[di - 1],
        routes[ri - 1]
    );
}

void dispatchShipment(Shipment** shipments, int count) {
    int idx;
    cin >> idx;
    shipments[idx - 1]->dispatch();
}

void viewShipments(Shipment** shipments, int count) {
    for (int i = 0; i < count; i++) {
        shipments[i]->display();
    }
}