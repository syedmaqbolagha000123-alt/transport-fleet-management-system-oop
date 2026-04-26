#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "Vehicle.h"
#include "Driver.h"
#include "Route.h"

class Shipment {
private:
    string shipmentID;
    double cargoTons;
    Vehicle* vehicle;
    Driver* driver;
    Route* route;
    double freightCost;
    bool dispatched;

public:
    Shipment(string, double, Vehicle*, Driver*, Route*);

    void dispatch();
    void display() const;

    string getID() const;
    bool isDispatched() const;
    double getCost() const;
};

#endif