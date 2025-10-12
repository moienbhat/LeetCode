#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // rotate the previous elements behind x
        for (int i = 0; i < sz - 1; i++) {
            // take front and push to back
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
