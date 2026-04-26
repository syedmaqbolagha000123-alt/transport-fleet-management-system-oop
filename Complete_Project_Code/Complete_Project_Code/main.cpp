#include <iomanip>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

// INCLUDING CUSTOM MADE HEADER FILES:
#include "AirVehicle.h"
#include "CargoPlane.h"
#include "Driver.h"
#include "Helicopter.h"
#include "LandVehicle.h"
#include "Person.h"
#include "Route.h"
#include "Shipment.h"
#include "Truck.h"
#include "Van.h"
#include "Vehicle.h"

// ========== UTILITY FUNCTIONS FOR MAIN PROGRAM ==========

// FUNCTIONS FOR CLEARER OUTPUTS:

void printLine()
{
    cout << "  ----------------------------------------\n";
}

void printHeader(string title)
{
    cout << "\n  ========================================\n";
    cout << "   " << title << "\n";
    cout << "  ========================================\n";
}

// DISPLAY VEHICLE FUNCTIONS (FIRST TWO IMPLEMENT OVERLOADING):

void showVehicle(Vehicle **fleet, int index, int total) // Search with Index #
{
    if (index < 0 || index >= total)
    {
        cout << "  Invalid index.\n";
        return;
    }
    fleet[index]->display();
}

void showVehicle(Vehicle **fleet, string plate, int total) // Search with Plate #
{
    for (int i = 0; i < total; i++)
    {
        if (fleet[i]->getPlate() == plate)
        {
            fleet[i]->display();
            return;
        }
    }
    cout << "  Vehicle with plate '" << plate << "' not found.\n";
}

void viewAllVehicles(Vehicle **fleet, int count)
{
    if (count == 0)
    {
        cout << "  No vehicles in fleet yet.\n";
        return;
    }
    printHeader("ALL VEHICLES");
    for (int i = 0; i < count; i++)
    {
        cout << "\n  [" << (i + 1) << "] " << *fleet[i] << "\n";
        printLine();
        fleet[i]->display();
    }
}

// FUNCIION TO ADD A NEW VEHICLE:

void addVehicle(Vehicle **fleet, int &count, int maxSize)
{
    if (count >= maxSize)
    {
        cout << "  Fleet is full!\n";
        return;
    }

    printHeader("ADD VEHICLE");
    cout << "  [1] Truck\n"
         << "  [2] Van\n"
         << "  [3] Cargo Plane\n"
         << "  [4] Helicopter\n"
         << "  Choice: ";
    int type;
    cin >> type;

    string plate, model;
    int year;
    double cap;

    cout << "  Plate No.      : ";
    getline(cin, plate);
    cout << "  Model          : ";
    getline(cin, model);
    cout << "  Year           : ";
    cin >> year;
    cout << "  Capacity (tons): ";
    cin >> cap;

    if (type == 1)
    {
        string permit;
        char heavy;
        cin.ignore();
        cout << "  Permit No      : ";
        getline(cin, permit);
        cout << "  Heavy truck? (y/n): ";
        cin >> heavy;
        fleet[count++] = new Truck(plate, model, year, cap, permit, (heavy == 'y' || heavy == 'Y'));
        cout << "  [OK] Truck added to fleet.\n";
    }
    else if (type == 2)
    {
        string permit;
        char fridge;
        cin.ignore();
        cout << "  Permit No      : ";
        getline(cin, permit);
        cout << "  Refrigerated? (y/n): ";
        cin >> fridge;
        fleet[count++] = new Van(plate, model, year, cap, permit, (fridge == 'y' || fridge == 'Y'));
        cout << "  [OK] Van added to fleet.\n";
    }
    else if (type == 3)
    {
        double altitude, range;
        int engines;
        string airport;
        cin.ignore();
        cout << "  Home Airport   : ";
        getline(cin, airport);
        cout << "  Altitude (ft)  : ";
        cin >> altitude;
        cout << "  No. of Engines : ";
        cin >> engines;
        cout << "  Range (km)     : ";
        cin >> range;
        fleet[count++] = new CargoPlane(plate, model, year, cap, altitude, airport, engines, range);
        cout << "  [OK] Cargo Plane added to fleet.\n";
    }
    else if (type == 4)
    {
        double altitude, rotorDiam;
        char winch;
        string airport;
        cin.ignore();
        cout << "  Home Airport   : ";
        getline(cin, airport);
        cout << "  Altitude (ft)  : ";
        cin >> altitude;
        cout << "  Rotor Diam (m) : ";
        cin >> rotorDiam;
        cout << "  Has Winch? (y/n): ";
        cin >> winch;
        fleet[count++] = new Helicopter(plate, model, year, cap, altitude, airport, (winch == 'y' || winch == 'Y'), rotorDiam);
        cout << "  [OK] Helicopter added to fleet.\n";
    }
    else
    {
        cout << "  Invalid type.\n";
    }
}

// VEHICLE SEARCH AND COMPARE:

void searchVehicle(Vehicle **fleet, int count)
{
    printHeader("SEARCH VEHICLE");
    cout << "  [1] Search by index\n"
         << "  [2] Search by plate\n"
         << "  Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "  Index (1 to " << count << "): ";
        int idx;
        cin >> idx;
        showVehicle(fleet, idx - 1, count);
    }
    else if (choice == 2)
    {
        cout << "  Plate number: ";
        string plate;
        cin.ignore();
        getline(cin, plate);
        showVehicle(fleet, plate, count);
    }
    else
    {
        cout << "  Invalid.\n";
    }
}

void compareVehicles(Vehicle **fleet, int count)
{
    if (count < 2)
    {
        cout << "  Need at least 2 vehicles to compare.\n";
        return;
    }
    printHeader("COMPARE VEHICLES");
    cout << "  Vehicle A index (1 to " << count << "): ";
    int a;
    cin >> a;
    cout << "  Vehicle B index (1 to " << count << "): ";
    int b;
    cin >> b;

    if (a < 1 || a > count || b < 1 || b > count)
    {
        cout << "  Invalid index.\n";
        return;
    }

    Vehicle *vehicle_a = fleet[a - 1];
    Vehicle *vehicle_b = fleet[b - 1];

    cout << "\n  A: " << *vehicle_a << "\n";
    cout << "  B: " << *vehicle_b << "\n";
    cout << "\n  A has more capacity than B? "
         << ((*vehicle_a > *vehicle_b) ? "Yes" : "No") << "\n";
    cout << "  A and B are the same vehicle?  "
         << ((*vehicle_a == *vehicle_b) ? "Yes" : "No") << "\n";
}

// DRIVER RELATED FUNCTIONS:

void addDriver(Driver **drivers, int &count, int maxSize)
{
    if (count >= maxSize)
    {
        cout << "  Driver list is full.\n";
        return;
    }

    printHeader("ADD DRIVER");
    string name, license;
    int age;

    cout << "  Name    : ";
    getline(cin, name);
    cout << "  Age     : ";
    cin >> age;
    cin.ignore();
    cout << "  License : ";
    getline(cin, license);

    drivers[count++] = new Driver(name, age, license);
    cout << "  [OK] Driver added.\n";
}

void viewDrivers(Driver **drivers, int count)
{
    if (count == 0)
    {
        cout << "  No drivers registered.\n";
        return;
    }

    printHeader("ALL DRIVERS");
    for (int i = 0; i < count; i++)
    {
        cout << "\n  [" << (i + 1) << "] "
             << drivers[i]->getRole() << " - "
             << drivers[i]->getName() << "\n";
        printLine();
        drivers[i]->display();
    }
}

void assignDriver(Vehicle **fleet, int vCount,
                  Driver **drivers, int dCount)
{
    if (vCount == 0 || dCount == 0)
    {
        cout << "  Need at least one vehicle and one driver.\n";
        return;
    }
    printHeader("ASSIGN DRIVER TO VEHICLE");

    cout << "  Vehicles:\n";
    for (int i = 0; i < vCount; i++)
        cout << "  [" << (i + 1) << "] " << *fleet[i] << "\n";

    cout << "  Select vehicle: ";
    int vi;
    cin >> vi;

    cout << "\n  Drivers:\n";
    for (int i = 0; i < dCount; i++)
        cout << "  [" << (i + 1) << "] " << drivers[i]->getName()
             << (drivers[i]->isOnDuty() ? " (On Duty)" : " (Free)") << "\n";

    cout << "  Select driver : ";
    int di;
    cin >> di;

    if (vi < 1 || vi > vCount || di < 1 || di > dCount)
    {
        cout << "  Invalid selection.\n";
        return;
    }

    drivers[di - 1]->setOnDuty(true);
    cout << "  [OK] " << drivers[di - 1]->getName()
         << " assigned to " << fleet[vi - 1]->getModel() << ".\n";
}

// FREIGHT COST CALCULATION:

void calcFreightCost(Vehicle **fleet, int count)
{
    if (count == 0)
    {
        cout << "  No vehicles in fleet.\n";
        return;
    }

    printHeader("FREIGHT COST CALCULATOR");
    cout << "  Vehicle index (1 to " << count << "): ";
    int idx;
    cin >> idx;
    if (idx < 1 || idx > count)
    {
        cout << "  Invalid.\n";
        return;
    }

    cout << "  Distance (km): ";
    double dist;
    cin >> dist;

    double cost = fleet[idx - 1]->calcCost(dist);
    cout << fixed << setprecision(2);
    cout << "\n  Vehicle  : " << *fleet[idx - 1] << "\n";
    cout << "  Distance : " << dist << " km\n";
    cout << "  Cost     : Rs " << cost << "\n";
}

// ROUTE RELATED FUNCTIONS:

void addRoute(Route **routes, int &count, int maxSize)
{
    if (count >= maxSize)
    {
        cout << "  Route list is full.\n";
        return;
    }

    printHeader("ADD ROUTE");
    string from, to;
    double dist;

    cin.ignore();
    cout << "  From (city)   : ";
    getline(cin, from);
    cout << "  To   (city)   : ";
    getline(cin, to);
    cout << "  Distance (km) : ";
    cin >> dist;

    routes[count++] = new Route(from, to, dist);
    cout << "  [OK] Route added.\n";
}

void viewRoutes(Route **routes, int count)
{
    if (count == 0)
    {
        cout << "  No routes added yet.\n";
        return;
    }

    printHeader("ALL ROUTES");
    for (int i = 0; i < count; i++)
    {
        cout << "\n  [" << (i + 1) << "] " << *routes[i] << "\n";
        printLine();
        routes[i]->display();
    }
}

// SHIPMENT FUNCTIONS:

void createShipment(Shipment **shipments, int &sCount, int maxSize, Vehicle **fleet, int vCount, Driver **drivers, int dCount, Route **routes, int rCount)
{

    if (sCount >= maxSize)
    {
        cout << "  Shipment list is full.\n";
        return;
    }
    if (vCount == 0 || dCount == 0 || rCount == 0)
    {
        cout << "  Need at least one vehicle, driver, and route first.\n";
        return;
    }

    printHeader("CREATE SHIPMENT");

    // Pick vehicle
    cout << "  Vehicles:\n";
    for (int i = 0; i < vCount; i++)
        cout << "  [" << (i + 1) << "] " << *fleet[i] << "\n";
    cout << "  Select vehicle: ";
    int vi;
    cin >> vi;
    if (vi < 1 || vi > vCount)
    {
        cout << "  Invalid.\n";
        return;
    }

    // Pick driver
    cout << "\n  Drivers:\n";
    for (int i = 0; i < dCount; i++)
        cout << "  [" << (i + 1) << "] " << drivers[i]->getName()
             << (drivers[i]->isOnDuty() ? " (On Duty)" : " (Free)") << "\n";
    cout << "  Select driver : ";
    int di;
    cin >> di;
    if (di < 1 || di > dCount)
    {
        cout << "  Invalid.\n";
        return;
    }

    // Pick route
    cout << "\n  Routes:\n";
    for (int i = 0; i < rCount; i++)
        cout << "  [" << (i + 1) << "] " << *routes[i] << "\n";
    cout << "  Select route  : ";
    int ri;
    cin >> ri;
    if (ri < 1 || ri > rCount)
    {
        cout << "  Invalid.\n";
        return;
    }

    // Cargo weight
    cout << "\n  Cargo weight (tons): ";
    double cargo;
    cin >> cargo;

    // Auto-generate shipment ID
    string sid = "SHP-00" + to_string(sCount + 1);

    shipments[sCount++] = new Shipment(sid, cargo, fleet[vi - 1], drivers[di - 1], routes[ri - 1]);
    cout << "  [OK] Shipment " << sid << " created (Pending).\n";
}

void dispatchShipment(Shipment **shipments, int count)
{
    if (count == 0)
    {
        cout << "  No shipments created yet.\n";
        return;
    }

    printHeader("DISPATCH SHIPMENT");
    for (int i = 0; i < count; i++)
    {
        cout << "  [" << (i + 1) << "] " << shipments[i]->getID() << (shipments[i]->isDispatched() ? " (Dispatched)" : " (Pending)") << "\n";
    }

    cout << "  Select shipment: ";
    int idx;
    cin >> idx;
    if (idx < 1 || idx > count)
    {
        cout << "  Invalid.\n";
        return;
    }

    shipments[idx - 1]->dispatch();
}

void viewShipments(Shipment **shipments, int count)
{
    if (count == 0)
    {
        cout << "  No shipments yet.\n";
        return;
    }

    printHeader("ALL SHIPMENTS");
    for (int i = 0; i < count; i++)
    {
        cout << "\n  [" << (i + 1) << "]\n";
        printLine();
        shipments[i]->display();
    }
}

// ========== MAIN PROGRAM ==========

int main()
{
    int v, d, r, s;
    cout << "  ENTER MAXIMUM CAPACITY FOR FOLLOWING DATA:\n";
    cout << "  1 -> VEHICLE FLEET,\n";
    cout << "  2 -> DRIVERS,\n";
    cout << "  3 -> ROUTES,\n";
    cout << "  4 -> SHIPMENTS,\n";
    cout << "  IN THAT ORDER:\n";
    cin >> v >> d >> r >> s;

    const int vMAX = v;
    const int dMAX = d;
    const int rMAX = r;
    const int sMAX = s;

    int vCount = 0, dCount = 0, rCount = 0, sCount = 0;

    // DMA; ALLOCATING POINTERS ON HEAP TO ACT AS DYNAMIC ARRAYS
    Vehicle **fleet = new Vehicle *[vMAX];
    Driver **drivers = new Driver *[dMAX];
    Route **routes = new Route *[rMAX];
    Shipment **shipments = new Shipment *[sMAX];

    // SAMPLE DATA
    fleet[vCount++] = new Truck("TRK-001", "Volvo-FH16", 2021, 25.0, "PERMIT-001", true);
    fleet[vCount++] = new Van("VAN-001", "Toyota-Hiace", 2022, 2.5, "PERMIT-231", false);
    fleet[vCount++] = new Van("VAN-002", "Daihatsu-Hijet", 2023, 0.5, "PERMIT-121", true);
    fleet[vCount++] = new CargoPlane("PLN-001", "Boeing-747-400", 2007, 115.0, 40000.0, "Jinnah International Airport KHI", 4, 12000.0);
    fleet[vCount++] = new Helicopter("HEL-001", "Mil-Mi-17", 1983, 3.8, 15000.0, "New Islamabad International Airport ISB", true, 21.29);
    drivers[dCount++] = new Driver("Maqbool Ahmed", 25, "HTV-LHR-001");
    drivers[dCount++] = new Driver("Mahboor Hussain", 28, "LTV-KHI-002");
    drivers[dCount++] = new Driver("Muhammad Tayyar", 28, "AIR-ISB-003");
    routes[rCount++] = new Route("Gwadar", "Khunjerab", 2500.0);
    routes[rCount++] = new Route("Karachi", "Peshawar", 1547.0);
    routes[rCount++] = new Route("Karachi", "Dubai", 1200.0);

    int choice, menu;

    do
    {
        system("cls");
        cout << "\n  ========================================\n";
        cout << "   FAST LOGISTICS - FLEET MANAGEMENT\n";
        cout << "  ========================================\n";
        cout << "  Vehicles: " << vCount
             << "  | Drivers: " << dCount
             << "  | Routes: " << rCount
             << "  | Shipments: " << sCount << "\n";
        cout << "  ----------------------------------------\n";
        cout << "  Select and Option:\n";
        cout << "  [1] Vehicles\n";
        cout << "  [2] Drivers\n";
        cout << "  [3] Routes\n";
        cout << "  [4] Shipments\n";
        cout << "  [0] Exit\n";
        cout << "  Choice: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            do
            {
                system("cls");
                cout << "  -- Vehicles --\n";
                cout << "  [1] Add Vehicle\n";
                cout << "  [2] View All Vehicles\n";
                cout << "  [3] Search Vehicle\n";
                cout << "  [4] Compare Vehicles\n";
                cout << "  [5] Calculate Freight Cost\n";
                cout << "  [0] Go Back\n";
                cout << "  Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    system("cls");
                    addVehicle(fleet, vCount, vMAX);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    viewAllVehicles(fleet, vCount);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    searchVehicle(fleet, vCount);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    compareVehicles(fleet, vCount);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    calcFreightCost(fleet, vCount);
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    cout << "  Invalid.\n";
                    system("pause");
                }
            } while (choice != 0);
            break;

        case 2:
            do
            {
                system("cls");
                cout << "  -- Drivers --\n";
                cout << "  [1] Add Driver\n";
                cout << "  [2] View All Drivers\n";
                cout << "  [0] Go Back\n";
                cout << "  Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    addDriver(drivers, dCount, dMAX);
                    system("pause");
                    break;
                case 2:
                    viewDrivers(drivers, dCount);
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    cout << "  Invalid.\n";
                    system("pause");
                }
            } while (choice != 0);
            break;

        case 3:
            do
            {
                system("cls");
                cout << "  -- Routes --\n";
                cout << "  [1] Add Route\n";
                cout << "  [2] View All Routes\n";
                cout << "  [0] Go Back\n";
                cout << "  Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    addRoute(routes, rCount, rMAX);
                    system("pause");
                    break;
                case 2:
                    viewRoutes(routes, rCount);
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid.\n";
                    system("pause");
                }
            } while (choice != 0);
            break;

        case 4:
            do
            {
                system("cls");
                cout << "  -- Shipments --\n";
                cout << "  [1] Create Shipment\n";
                cout << "  [2] Dispatch Shipment\n";
                cout << "  [3] View All Shipments\n";
                cout << "  [0] Go Back\n";
                cout << "  Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    createShipment(shipments, sCount, sMAX, fleet, vCount, drivers, dCount, routes, rCount);
                    system("pause");
                    break;
                case 2:
                    dispatchShipment(shipments, sCount);
                    system("pause");
                    break;
                case 3:
                    viewShipments(shipments, sCount);
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    cout << "  Invalid.\n";
                    system("pause");
                }
            } while (choice != 0);
            break;

        case 0:
            cout << "  Goodbye!\n";
            break;

        default:
            cout << "  Invalid option.\n";
            system("pause");
            break;
        }
    } while (menu != 0);

    // DMA CLEANUP
    for (int i = 0; i < vCount; i++)
        delete fleet[i];
    for (int i = 0; i < dCount; i++)
        delete drivers[i];
    for (int i = 0; i < rCount; i++)
        delete routes[i];
    for (int i = 0; i < sCount; i++)
        delete shipments[i];
    delete[] fleet;
    delete[] drivers;
    delete[] routes;
    delete[] shipments;

    return 0;
}
