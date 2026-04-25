#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "AirVehicle.h"

class Helicopter : public AirVehicle {
private:
    bool hasWinch;
    double rotorDiameterM;

public:
    Helicopter(string, string, int, double, double, string, bool, double);

    double calcCost(double) const override;
    string getType() const override;
    void display() const override;
};

#endif