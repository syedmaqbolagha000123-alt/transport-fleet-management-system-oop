#include "Route.h"

Route::Route(string f, string t, double d)
    : from(f), to(t), distanceKm(d) {}

string Route::getFrom() const { return from; }
string Route::getTo() const { return to; }
double Route::getDistance() const { return distanceKm; }

void Route::display() const {
    cout << "  From     : " << from << "\n"
         << "  To       : " << to << "\n"
         << "  Distance : " << distanceKm << " km\n";
}

ostream& operator<<(ostream& os, const Route& r) {
    os << r.from << " -> " << r.to << " (" << r.distanceKm << " km)";
    return os;
}