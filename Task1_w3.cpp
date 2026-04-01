#include <iostream>
#include "myStack.h"
using namespace std;

int main() {
    myStack<int> s(5);
    int choice, val;

    do {
        cout << "\n1.Push 2.Pop 3.Top 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Value: "; cin >> val; s.push(val); break;
        case 2: cout << "Popped: " << s.pop() << endl; break;
        case 3: cout << "Top: " << s.top() << endl; break;
        case 4: s.display(); break;
        }
    } while (choice != 5);

    return 0;
}