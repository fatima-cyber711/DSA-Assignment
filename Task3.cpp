#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* head = nullptr;

// inserting at specific pos
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node(value);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid Position"<<endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Invalid Position"<<endl;
        return;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void search(int key) { // searching
    Node* temp = head;
    int pos = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Element found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found"<<endl;
}

int countNodes() { //counting
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}
void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL"<<endl;
}

int main() {
    int choice, value, pos;

    do {
        cout << "menu";
        cout << "1. Insert at Position"<<endl;
        cout << "2. Delete at Position"<<endl;
        cout << "3. Search Element"<<endl;
        cout << "4. Count Nodes"<<endl;
        cout << "5. Display List"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Enter position: ";
            cin >> pos;
            deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;

        case 4:
            cout << "Total nodes: " << countNodes() << endl;
            break;

        case 5:
            display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}