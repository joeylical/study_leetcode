#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        while(size-->1) {
            int t = q1.front();
            q1.pop();
            q2.push(t);
        }
        int result = q1.front();
        q1.pop();
        while(!q2.empty()) {
            int t = q2.front();
            q2.pop();
            q1.push(t);
        }

        return result;
    }
    
    int top() {
        int size = q1.size();
        while(size-->1) {
            int t = q1.front();
            q1.pop();
            q2.push(t);
        }
        int result = q1.front();
        q2.push(q1.front());
        q1.pop();
        while(!q2.empty()) {
            int t = q2.front();
            q2.pop();
            q1.push(t);
        }

        return result;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
}

