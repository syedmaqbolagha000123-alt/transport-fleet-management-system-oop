#include "Van.h"
#include <iostream>
#include <iomanip>
using namespace std;

Van::Van(string plate, string model, int year,
         double cap, string permit, bool fridge)
    : LandVehicle(plate, model, year, cap, permit),
      isRefrigerated(fridge) {}

double Van::calcCost(double distanceKm) const
{
    double base = distanceKm * capacityTons * 5;
    double surcharge = isRefrigerated ? 300.0 : 0.0;
    return base + surcharge;
}

string Van::getType() const
{
    return isRefrigerated ? "Refrigerated Van" : "Delivery Van";
}

void Van::display() const
{
    cout << "\n  -- VAN --\n";
    LandVehicle::display();
    cout << "  Fridge   : " << (isRefrigerated ? "Yes" : "No") << "\n";
    cout << fixed << setprecision(2)
         << "  Cost/500km: Rs " << calcCost(500) << "\n";
}