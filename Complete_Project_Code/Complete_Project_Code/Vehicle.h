#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle {
private:
    string plate;
    string model;
    int year;

protected:
    double capacityTons;

public:
    Vehicle(string, string, int, double);
    virtual ~Vehicle();

    virtual double calcCost(double) const = 0;
    virtual string getType() const = 0;

    virtual void display() const;

    string getPlate() const;
    string getModel() const;
    int getYear() const;
    double getCapacity() const;

    bool operator==(const Vehicle&) const;
    bool operator>(const Vehicle&) const;

    friend ostream& operator<<(ostream&, const Vehicle&);
};

#endif