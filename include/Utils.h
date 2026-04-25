#ifndef UTILS_H
#define UTILS_H

#include "Vehicle.h"
#include "Driver.h"
#include "Route.h"
#include "Shipment.h"

// Function Overloading
void showVehicle(Vehicle** fleet, int index, int total);
void showVehicle(Vehicle** fleet, string plate, int total);

// Helper functions
void printLine();
void printHeader(string title);

// Vehicle Menu
void addVehicle(Vehicle** fleet, int& count, int maxSize);
void viewAllVehicles(Vehicle** fleet, int count);
void searchVehicle(Vehicle** fleet, int count);
void compareVehicles(Vehicle** fleet, int count);
void calcFreightCost(Vehicle** fleet, int count);

// Driver Menu
void addDriver(Driver** drivers, int& count, int maxSize);
void viewDrivers(Driver** drivers, int count);
void assignDriver(Vehicle** fleet, int vCount,
                  Driver** drivers, int dCount);

// Route Menu
void addRoute(Route** routes, int& count, int maxSize);
void viewRoutes(Route** routes, int count);

// Shipment Menu
void createShipment(Shipment** shipments, int& sCount, int maxSize,
                    Vehicle** fleet, int vCount,
                    Driver** drivers, int dCount,
                    Route** routes, int rCount);

void dispatchShipment(Shipment** shipments, int count);
void viewShipments(Shipment** shipments, int count);

#endif