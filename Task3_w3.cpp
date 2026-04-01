#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> parking, temp;
    int choice, car;

    do {
        cout << "\n1.Park 2.Remove 3.Display 4.Search 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (parking.size() == 8) cout << "Parking Full" << endl;
            else { cin >> car; parking.push(car); }
            break;

        case 2:
            cin >> car;
            while (!parking.empty() && parking.top() != car) {
                temp.push(parking.top());
                parking.pop();
            }
            if (parking.empty()) cout << "Car not found" << endl;
            else parking.pop();
            while (!temp.empty()) {
                parking.push(temp.top());
                temp.pop();
            }
            break;

        case 3: {
            stack<int> t = parking;
            while (!t.empty()) { cout << t.top() << " "; t.pop(); }
            cout << endl;
            break;
        }

        case 4: {
            stack<int> t = parking;
            bool found = false;
            cin >> car;
            while (!t.empty()) {
                if (t.top() == car) found = true;
                t.pop();
            }
            cout << (found ? "Found" : "Not Found") << endl;
            break;
        }
        }
    } while (choice != 5);
}