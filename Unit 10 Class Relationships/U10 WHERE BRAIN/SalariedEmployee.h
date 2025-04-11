//
// Created by snoutibur on 11/13/24.
//

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <iostream>
#include <sstream>
#include "Employee.h"

using namespace std;

class SalariedEmployee : public Employee {
    public:
    SalariedEmployee(string name, int year, int month, int day, double salary) : Employee(name, year, month, day), salary(salary) {}
    virtual string str();

protected:
    double salary;
};

string SalariedEmployee::str() {
    stringstream ss;
    ss << Employee::str();
    ss << "Salary" << salary << endl;
    return ss.str();
}


#endif //SALARIEDEMPLOYEE_H
