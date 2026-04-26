#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <iostream>
using namespace std;

class Route {
private:
    string from;
    string to;
    double distanceKm;

public:
    Route(string, string, double);

    string getFrom() const;
    string getTo() const;
    double getDistance() const;

    void display() const;

    friend ostream& operator<<(ostream&, const Route&);
};

#endif