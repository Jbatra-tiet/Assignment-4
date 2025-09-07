#include<iostream>
using namespace std;

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = value;
        cout << value << " enqueued into queue." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Nothing to dequeue." << endl;
    } else {
        cout << cq[front] << " dequeued from queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << cq[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << (isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 7);

    return 0;
}
