//
// Created by snoutibur on 11/13/24.
//

#ifndef SALESEMPLOYEE_H
#define SALESEMPLOYEE_H

#include "SalariedEmployee.h"

class SalesEmployee : public SalariedEmployee {
public:
    SalesEmployee(string name, int year, int month, int day, double salarly, double commission, double sales) :
    SalariedEmployee(name, year, month, day, salarly), commission(commission), sales(sales) {}

    virtual string str();
private:
    double sales, commission;
};

string SalesEmployee::str() {
    stringstream ss;
    ss << SalariedEmployee::str();
    ss << "Sales: " << sales << endl;
    ss << "Commission: " << commission << endl;
}


#endif //SALESEMPLOYEE_H
