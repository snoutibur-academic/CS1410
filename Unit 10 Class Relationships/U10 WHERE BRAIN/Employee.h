//
// Created by snoutibur on 11/13/24.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <chrono>
#include <iostream>

#include "Address.h"
#include "Date.h"

using std::string;
using std::stringstream;

class Employee {
public:
    Employee(string name, int month, int year, int day) : name(name), startDate(year, month, day) {}
    ~Employee();

    virtual string str();
    void setAddress(string street, string city);

    friend ostream& operator << (ostream& out, const Employee& me);
protected:
    string name;
    Address * address;
    Date startDate;
};

inline Employee::~Employee() {
    if(address) {
        delete address;
    }
}


inline string Employee::str() {
    stringstream ss;
    ss << name << endl;
    ss << startDate << endl;
    if(address) {
        ss << *address;
    }

    return ss.str();
}

inline void Employee::setAddress(string street, string city) {
    address = new Address(street, city);
}


inline ostream& operator << (ostream& out, Employee& me) {
    out << me.str();
    return out;
}


#endif //EMPLOYEE_H
