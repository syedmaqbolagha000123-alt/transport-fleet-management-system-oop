#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"

class Driver : public Person {
private:
    string licenseNo;
    bool onDuty;

public:
    Driver(string, int, string);

    string getRole() const override;
    void display() const override;

    void setOnDuty(bool);
    bool isOnDuty() const;
    string getLicense() const;
};

#endif