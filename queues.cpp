#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string address;
    int priority;
    Node* next;
};

class ParcelQueue {
private:
    Node *front, *rear;

public:
    ParcelQueue() {
        front = rear = nullptr;
    }

    void enqueue(int id, string address, int priority) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->address = address;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Parcel " << id << " enqueued. Address: " << address << ", Priority: " << priority << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeuing Parcel ID: " << temp->id << endl;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue Parcels:\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Address: " << temp->address << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    int getFrontID() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->id;
    }

    int getSize() {
        int size = 0;
        Node* temp = front;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        cout << "Queue size: " << size << endl;
        return size;
    }

    int getRearID() {
        if (rear == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->id;
    }
};

int main() {
    ParcelQueue pq;

    pq.enqueue(101, "123 Main St", 2);
    pq.enqueue(102, "456 Elm St", 1);
    pq.enqueue(103, "789 Oak Rd", 3);

    cout << "Front Parcel ID: " << pq.getFrontID() << endl;
    pq.getSize();

    pq.display();

    pq.dequeue();
    pq.dequeue();

    cout << "Front Parcel ID: " << pq.getFrontID() << endl;
    cout << "Rear Parcel ID: " << pq.getRearID() << endl;

    pq.dequeue();
    pq.dequeue(); // Underflow test

    return 0;
}
