//
// Created by snoutibur on 11/13/24.
//

#ifndef WAGEDEMPLOYEE_H
#define WAGEDEMPLOYEE_H

#include "Employee.h"

using std::string;
using std::stringstream;

class WagedEmployee : public Employee {
public:
    WagedEmployee(string name, int year, int month, int day, double wage, double hours) :  Employee(name, year, month, day), wage(wage), hours(hours) {};
    virtual string str();

protected:
    double wage;
    double hours;
};

inline string WagedEmployee::str() {
    stringstream ss;
    ss << Employee::str() << " " << wage << " " << hours << endl;
    ss << "salary: " << wage*hours << endl;
    return ss.str();
}


#endif //WAGEDEMPLOYEE_H
