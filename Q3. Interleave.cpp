#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must have even number of elements." << endl;
        return;
    }

    int halfSize = q.size() / 2;
    stack<int> s;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
