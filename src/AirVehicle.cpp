#include "AirVehicle.h"
#include <iostream>
using namespace std;

AirVehicle::AirVehicle(string plate, string model, int year,
                       double cap, double altitude, string airport)
    : Vehicle(plate, model, year, cap),
      maxAltitudeFt(altitude), airportCode(airport) {}

AirVehicle::~AirVehicle() {}

void AirVehicle::display() const {
    Vehicle::display();
    cout << "  Altitude : " << maxAltitudeFt << " ft\n"
         << "  Airport  : " << airportCode << "\n";
}

string AirVehicle::getAirport() const { return airportCode; }
double AirVehicle::getAltitude() const { return maxAltitudeFt; }