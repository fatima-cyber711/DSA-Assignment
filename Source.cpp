//class LinkedListADT {
//private:
//    Node* head;
//
//public:
//    LinkedListADT() {
//        head = nullptr;
//    }
//
//    void insertAtBeginning(int value) {
//        Node* newNode = new Node(value);
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void insertAtEnd(int value) {
//        Node* newNode = new Node(value);
//
//        if (head == nullptr) {
//            head = newNode;
//            return;
//        }
//
//        Node* temp = head;
//        while (temp->next != nullptr)
//            temp = temp->next;
//
//        temp->next = newNode;
//    }
//
//    void deleteByValue(int value) {
//        if (head == nullptr) return;
//
//        if (head->data == value) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//            return;
//        }
//
//        Node* temp = head;
//        while (temp->next != nullptr && temp->next->data != value)
//            temp = temp->next;
//
//        if (temp->next != nullptr) {
//            Node* del = temp->next;
//            temp->next = temp->next->next;
//            delete del;
//        }
//    }
//
//    void display() {
//        Node* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data << " -> ";
//            temp = temp->next;
//        }
//        cout << "NULL"<<endl;
//    }
//};