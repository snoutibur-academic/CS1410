//
// Created by snoutibur on 11/13/24.
//

#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;

class Address {
public:
    Address(string street, string city) : street(street), city(city) {}
    friend ostream& operator << (ostream& out, const Address& me);
protected:
    string street;
    string city;
};

ostream& operator << (ostream& out, const Address& me) {
    out << me.street << me.city << endl;
    return out;
}

#endif //ADDRESS_H
