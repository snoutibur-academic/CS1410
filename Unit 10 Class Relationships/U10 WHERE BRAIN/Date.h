//
// Created by snoutibur on 11/13/24.
//

#ifndef DATE_H
#define DATE_H

using namespace std;

class Date {
public:
    Date(int year, int month, int day) : year(year), month(month), day(day) {}
    friend ostream& operator << (ostream& out, const Date& me);

protected:
    int year, month, day;
};

ostream& operator << (ostream& out, const Date& me) {
    out << "Start date: " << me.year << "/" << me.month << "/" << me.day << endl;
    return out;
}

#endif //DATE_H
