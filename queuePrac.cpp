#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;  // remove from here
    Node* back;   // add to here

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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    // queue front-to-back: 10, 20, 30

    cout << "Front is: " << q.peekFront() << "\n";  // expect 10

    cout << "Dequeued: " << q.dequeue() << "\n";     // expect 10
    cout << "Dequeued: " << q.dequeue() << "\n";     // expect 20

    cout << "Front is now: " << q.peekFront() << "\n"; // expect 30

    cout << "Is empty? " << (q.isEmpty() ? "yes" : "no") << "\n"; // expect no

    return 0;
}