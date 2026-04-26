#include "CargoPlane.h"
#include <iostream>
#include <iomanip>
using namespace std;

CargoPlane::CargoPlane(string plate, string model, int year,
                       double cap, double altitude, string airport,
                       int engines, double range)
    : AirVehicle(plate, model, year, cap, altitude, airport),
      engineCount(engines), rangeKm(range) {}

double CargoPlane::calcCost(double distanceKm) const
{
    double handlingFee = 8000.0;
    double flightCost = distanceKm * capacityTons * 15;
    return handlingFee + flightCost;
}

string CargoPlane::getType() const
{
    return "Cargo Plane";
}

void CargoPlane::display() const
{
    cout << "\n  -- CARGO PLANE --\n";
    AirVehicle::display();
    cout << "  Engines  : " << engineCount << "\n"
         << "  Range    : " << rangeKm << " km\n";
    cout << fixed << setprecision(2)
         << "  Cost/500km: Rs " << calcCost(500) << "\n";
}