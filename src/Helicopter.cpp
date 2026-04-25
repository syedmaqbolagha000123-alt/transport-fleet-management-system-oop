#include "Helicopter.h"
#include <iostream>
#include <iomanip>
using namespace std;

Helicopter::Helicopter(string plate, string model, int year,
                       double cap, double altitude, string airport,
                       bool winch, double rotorDiam)
    : AirVehicle(plate, model, year, cap, altitude, airport),
      hasWinch(winch), rotorDiameterM(rotorDiam) {}

double Helicopter::calcCost(double distanceKm) const {
    double flightCost = distanceKm * capacityTons * 0.45;
    double winchCharge = hasWinch ? 1500.0 : 0.0;
    return flightCost + winchCharge;
}

string Helicopter::getType() const {
    return hasWinch ? "Helicopter (Winch)" : "Helicopter";
}

void Helicopter::display() const {
    cout << "\n  -- HELICOPTER --\n";
    AirVehicle::display();
    cout << "  Rotor    : " << rotorDiameterM << " m diameter\n"
         << "  Winch    : " << (hasWinch ? "Yes" : "No") << "\n";
    cout << fixed << setprecision(2)
         << "  Cost/500km: Rs " << calcCost(500) << "\n";
}