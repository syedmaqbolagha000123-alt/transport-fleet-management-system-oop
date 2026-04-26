#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"

class LandVehicle : public Vehicle {
protected:
    string permitNo;

public:
    LandVehicle(string, string, int, double, string);
    virtual ~LandVehicle();

    void display() const override;
};

#endif