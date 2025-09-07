#include<iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1 || front > rear;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        cout << value << " enqueued into queue." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Nothing to dequeue." << endl;
    } else {
        cout << queue[front++] << " dequeued from queue." << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
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
