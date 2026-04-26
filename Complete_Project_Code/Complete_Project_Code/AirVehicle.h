#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include "Vehicle.h"

class AirVehicle : public Vehicle {
protected:
    double maxAltitudeFt;
    string airportCode;

public:
    AirVehicle(string, string, int, double, double, string);
    virtual ~AirVehicle();

    void display() const override;

    string getAirport() const;
    double getAltitude() const;
};

#endif