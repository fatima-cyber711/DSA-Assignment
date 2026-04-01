#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s, minStack;
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    int pop() {
        if (s.empty()) { cout << "Stack Empty" << endl; return -1; }
        int val = s.top(); s.pop();
        if (val == minStack.top()) minStack.pop();
        return val;
    }

    int top() {
        if (s.empty()) { cout << "Stack Empty" << endl; return -1; }
        return s.top();
    }

    int getMin() {
        if (minStack.empty()) { cout << "Stack Empty" << endl; return -1; }
        return minStack.top();
    }

    bool isEmpty() { return s.empty(); }

    void display() {
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    MinStack s;
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.Top 4.Display 5.Min 6.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: cin >> val; s.push(val); break;
        case 2: cout << "Popped: " << s.pop() << endl; break;
        case 3: cout << "Top: " << s.top() << endl; break;
        case 4: s.display(); break;
        case 5: cout << "Min: " << s.getMin() << endl; break;
        }
    } while (choice != 6);
}