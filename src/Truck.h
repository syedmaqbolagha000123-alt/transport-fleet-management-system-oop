#ifndef TRUCK_H
#define TRUCK_H

#include "LandVehicle.h"

class Truck : public LandVehicle {
private:
    bool isHeavy;

public:
    Truck(string, string, int, double, string, bool);

    double calcCost(double) const override;
    string getType() const override;
    void display() const override;
};

#endif