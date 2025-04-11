#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> qi;
    qi.add(1);
    qi.add(2);
    qi.add(3);

    Queue<string> qs;
    qs.add("H1");
    qs.add("Flyin2");
    qs.add("Toast3");

    cout << qi << endl;
    cout << qs;
}