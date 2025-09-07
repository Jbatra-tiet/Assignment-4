#include<iostream>
#include<queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};

    for (char c : str) {
        if (c == ' ') continue;
        freq[c - 'a']++;
        q.push(c);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    firstNonRepeating(input);

    return 0;
}
