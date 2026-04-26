#include "Driver.h"
#include <iostream>
using namespace std;

Driver::Driver(string name, int age, string license)
    : Person(name, age), licenseNo(license), onDuty(false) {}

string Driver::getRole() const { return "Driver"; }

void Driver::display() const
{
    cout << "  Name    : " << getName() << "\n"
         << "  Age     : " << getAge() << "\n"
         << "  License : " << licenseNo << "\n"
         << "  On Duty : " << (onDuty ? "Yes" : "No") << "\n";
}

void Driver::setOnDuty(bool status) { onDuty = status; }
bool Driver::isOnDuty() const { return onDuty; }
string Driver::getLicense() const { return licenseNo; }