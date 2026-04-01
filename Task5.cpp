#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int priority;
    Student* next;

    Student(string n, int p) {
        name = n;
        priority = p;
        next = nullptr;
    }
};

class BookQueue {
private:
    Student* head;

public:
    BookQueue() {
        head = nullptr;
    }
    void addStudent(string name, int priority) {
        Student* newStudent = new Student(name, priority);
        if (head == nullptr || priority > head->priority) {
            newStudent->next = head;
            head = newStudent;
            return;
        }

        Student* temp = head;

        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;
        }

        newStudent->next = temp->next;
        temp->next = newStudent;
    }
    void removeStudent(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            Student* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Student* temp = head;

        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Student* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void updatePriority(string name, int newPriority) {
        removeStudent(name);
        addStudent(name, newPriority);
    }

    void serveStudent() {
        if (head == nullptr) return;

        cout << "Served: " << head->name << endl;

        Student* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Student* temp = head;

        while (temp != nullptr) {
            cout << temp->name << "(" << temp->priority << ") -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    int count() {
        int c = 0;
        Student* temp = head;

        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }

        return c;
    }
};

int main() {

    BookQueue book1;
    BookQueue book2;

    book1.addStudent("Ali", 2);
    book1.addStudent("Ahmed", 3);
    book1.addStudent("Sara", 1);

    cout << "Book 1 Queue:\n";
    book1.display();

    book1.updatePriority("Sara", 5);

    cout << "\nAfter updating Sara priority:\n";
    book1.display();

    book1.serveStudent();

    cout << "\nAfter serving:\n";
    book1.display();

    cout << "Total students: " << book1.count() << endl;
    book2.addStudent("Zain", 1);
    book2.addStudent("Hina", 4);

    cout << "\nBook 2 Queue:\n";
    book2.display();

    return 0;
}