// a)
#include <iostream>
using namespace std;

class Queue {
    char a[1000];
    int f=0, r=0, cnt=0;
public:
    void push(char x){ a[r]=x; r=(r+1)%1000; cnt++; }
    void pop(){ if(cnt>0){ f=(f+1)%1000; cnt--; } }
    char front(){ return cnt>0 ? a[f] : 0; }
    bool empty(){ return cnt==0; }
    int size(){ return cnt; }
};

class StackTwoQueues {
    Queue q1, q2;
public:
    void push(char x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){ if(!q1.empty()) q1.pop(); }
    char top(){ return q1.front(); }
    bool empty(){ return q1.empty(); }
};

int main(){
    StackTwoQueues s;
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

// b)
#include <iostream>
using namespace std;

class Queue {
    char a[1000];
    int f=0, r=0, cnt=0;
public:
    void push(char x){ a[r]=x; r=(r+1)%1000; cnt++; }
    void pop(){ if(cnt>0){ f=(f+1)%1000; cnt--; } }
    char front(){ return cnt>0 ? a[f] : 0; }
    bool empty(){ return cnt==0; }
    int size(){ return cnt; }
};

class StackOneQueue {
    Queue q;
public:
    void push(char x){
        q.push(x);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            char t = q.front();
            q.pop();
            q.push(t);
        }
    }
    void pop(){ if(!q.empty()) q.pop(); }
    char top(){ return q.front(); }
    bool empty(){ return q.empty(); }
};

int main(){
    StackOneQueue s;
    s.push('a');
    s.push('b');
    s.push('c');
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

