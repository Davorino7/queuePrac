#include <iostream>                 // Added user input and a main menu
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;  
    Node* back;   

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

    if (front == nullptr) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}
    int dequeue() {
        if (front == nullptr) {
            cout << "front is empty.\n";
            return -1;
        } else { 
            int value = front->data;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) back = nullptr;
            delete temp;
            return value;
        }
    }
    int peekFront() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};
int main() {

int choice, value;
Queue q;
do {
    cout << "\n===== Queue Menu =====\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Peek front\n4. Check if empty\n5. Exit\n";
    cout << "Choose: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Please enter value: ";
            cin >> value;
            q.enqueue(value);
            cout << value << " is added.\n";
            break;
        } 
        case 2: {
            cout << "Dequeued: " << q.dequeue() << "\n";
            break;
        } 
        case 3: {
            if (q.isEmpty()) {
                cout << "The queue is empty.";
            } else {
                cout << "Front is now: " << q.peekFront() << "\n";
            }
            break;
        } 
        case 4: {
            cout << "The queue is: " << (q.isEmpty() ? "empty" : "not empty") << "\n";
            break;
        } 
        case 5: {
            cout << "Program closing...\n";
            break;
        }
        default:
        cout << "Invalid input. Please enter between (1-5).\n";
        }
    } while (choice != 5);

    return 0;
}