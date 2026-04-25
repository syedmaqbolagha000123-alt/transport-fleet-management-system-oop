#ifndef VAN_H
#define VAN_H

#include "LandVehicle.h"

class Van : public LandVehicle {
private:
    bool isRefrigerated;

public:
    Van(string, string, int, double, string, bool);

    double calcCost(double) const override;
    string getType() const override;
    void display() const override;
};

#endif