#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    cout << "Link List\n";

    Stack <string> s1;
    s1.push("dingus1");
    s1.push("toaster2");
    s1.push("bathtup3");
    s1.push("spaceship4");
    cout << s1 << endl;

    Stack <int> s2;
    for(int i = 1; i <= 10; i++) {
        s2.push(i);
    }
    cout << s2 << endl;

    return 0;
}
