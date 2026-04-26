#include "Shipment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Shipment::Shipment(string id, double cargo,
                   Vehicle* v, Driver* d, Route* r)
    : shipmentID(id), cargoTons(cargo),
      vehicle(v), driver(d), route(r),
      freightCost(0.0), dispatched(false) {}

void Shipment::dispatch() {
    if (dispatched) {
        cout << "  [!] Shipment already dispatched.\n";
        return;
    }

    if (cargoTons > vehicle->getCapacity()) {
        cout << "  [!] Cargo exceeds capacity.\n";
        return;
    }

    double baseCost = vehicle->calcCost(route->getDistance());
    double loadFactor = cargoTons / vehicle->getCapacity();
    double scaledCost = baseCost * loadFactor;

    double surcharge = (cargoTons > 5.0) ? (cargoTons - 5.0) * 50.0 : 0.0;

    freightCost = scaledCost + surcharge;
    driver->setOnDuty(true);
    dispatched = true;

    cout << fixed << setprecision(2);
    cout << "  [OK] Shipment " << shipmentID << " dispatched!\n";
    cout << "  Freight Cost : Rs " << freightCost << "\n";
}

void Shipment::display() const {
    cout << "  Shipment ID  : " << shipmentID << "\n"
         << "  Cargo        : " << cargoTons << " tons\n"
         << "  Status       : "
         << (dispatched ? "Dispatched" : "Pending") << "\n";
    cout << "  Vehicle      : " << *vehicle << "\n";
    cout << "  Driver       : " << driver->getName()
         << " (" << driver->getLicense() << ")\n";
    cout << "  Route        : " << *route << "\n";

    if (dispatched)
        cout << fixed << setprecision(2)
             << "  Freight Cost : Rs " << freightCost << "\n";
}

string Shipment::getID() const { return shipmentID; }
bool Shipment::isDispatched() const { return dispatched; }
double Shipment::getCost() const { return freightCost; }