#include<iostream>
using namespace std;

//linked list is a ds in which each element is called node
//node=value,next node address(pointer)

class node {
public:
	int data;
	node* next;

	node(int value) {
		data = value;
		next = nullptr;
	}
};

class linkedlist {
//private so that no one can do changing in the list
private:
	node* head;
//public so that every time ctor is called creates an empty list
public:
	linkedlist() {
		head = nullptr;
	}
	void CreateNode(int value) {
		node* newNode = new node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void Display() {
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	linkedlist list;
	list.CreateNode(1);
	list.CreateNode(2);
	list.CreateNode(3);
	list.CreateNode(4);
	list.CreateNode(5);
	list.CreateNode(6);


	list.Display();
	return 0;
}
