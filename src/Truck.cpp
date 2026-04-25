#include "Truck.h"
#include <iostream>
#include <iomanip>
using namespace std;

Truck::Truck(string plate, string model, int year,
             double cap, string permit, bool heavy)
    : LandVehicle(plate, model, year, cap, permit),
      isHeavy(heavy) {}

double Truck::calcCost(double distanceKm) const {
    double rate = isHeavy ? 0.08 : 0.05;
    return distanceKm * capacityTons * rate;
}

string Truck::getType() const {
    return isHeavy ? "Heavy Truck" : "Medium Truck";
}

void Truck::display() const {
    cout << "\n  -- TRUCK --\n";
    LandVehicle::display();
    cout << "  Type     : " << (isHeavy ? "Heavy" : "Medium") << "\n";
    cout << fixed << setprecision(2)
         << "  Cost/500km: Rs " << calcCost(500) << "\n";
}