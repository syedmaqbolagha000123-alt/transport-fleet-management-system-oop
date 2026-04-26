#include "Vehicle.h"

Vehicle::Vehicle(string p, string m, int y, double cap)
    : plate(p), model(m), year(y), capacityTons(cap) {}

Vehicle::~Vehicle() {}

void Vehicle::display() const {
    cout << "  Plate    : " << plate << "\n"
         << "  Model    : " << model << "\n"
         << "  Year     : " << year << "\n"
         << "  Capacity : " << capacityTons << " tons\n";
}

string Vehicle::getPlate() const { return plate; }
string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
double Vehicle::getCapacity() const { return capacityTons; }

bool Vehicle::operator==(const Vehicle& other) const {
    return plate == other.plate;
}

bool Vehicle::operator>(const Vehicle& other) const {
    return capacityTons > other.capacityTons;
}

ostream& operator<<(ostream& os, const Vehicle& v) {
    os << "[" << v.getType() << "] " << v.model
       << " | Plate: " << v.plate
       << " | Cap: " << v.capacityTons << "t";
    return os;
}