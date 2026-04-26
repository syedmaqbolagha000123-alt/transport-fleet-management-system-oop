#ifndef CARGOPLANE_H
#define CARGOPLANE_H

#include "AirVehicle.h"

class CargoPlane : public AirVehicle
{
private:
    int engineCount;
    double rangeKm;

public:
    CargoPlane(string, string, int, double, double, string, int, double);

    int getEngines() const;
    double getRange() const;
    double calcCost(double) const override;
    string getType() const override;
    void display() const override;
};

#endif