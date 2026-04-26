#include "LandVehicle.h"
#include <iostream>
using namespace std;

LandVehicle::LandVehicle(string plate, string model, int year,
                         double cap, string permit)
    : Vehicle(plate, model, year, cap), permitNo(permit) {}

LandVehicle::~LandVehicle() {}

string LandVehicle::getPermit() const { return permitNo; }

void LandVehicle::display() const
{
    Vehicle::display();
    cout << "  Permit   : " << permitNo << "\n";
}
