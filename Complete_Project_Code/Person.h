#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string, int);
    virtual ~Person();

    virtual string getRole() const = 0;
    virtual void display() const = 0;

    string getName() const;
    int getAge() const;
};

#endif
