#include <iostream>
using namespace std;

class Patient {
public:
    string name;
    Patient* next;

    Patient(string n) {
        name = n;
        next = nullptr;
    }
};

class HospitalQueue {
private:
    Patient* head;

public:
    HospitalQueue() {
        head = nullptr;
    }

    void addPatient(string name) {
        Patient* newPatient = new Patient(name);

        if (head == nullptr) {
            head = newPatient;
            return;
        }

        Patient* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newPatient;
    }

    void removePatient(string name) {
        if (head == nullptr) {
            cout << "No patients in queue\n";
            return;
        }

        if (head->name == name) {
            Patient* temp = head;
            head = head->next;
            delete temp;
            cout << name << " removed from queue\n";
            return;
        }

        Patient* temp = head;

        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Patient* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << name << " removed from queue\n";
        }
        else {
            cout << "Patient not found\n";
        }
    }


    void display() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Patient* temp = head;

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    int count() {
        int c = 0;
        Patient* temp = head;

        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }

        return c;
    }
};

int main() {
    HospitalQueue queue;
    queue.addPatient("Ali");
    queue.addPatient("Sara");
    queue.addPatient("Ahmed");

    cout << "Current Queue:\n";
    queue.display();

    cout << "\nTotal Patients: " << queue.count() << endl;
    queue.removePatient("Sara");

    cout << "\nAfter Removal:\n";
    queue.display();

    cout << "Total Patients: " << queue.count() << endl;

    return 0;
}