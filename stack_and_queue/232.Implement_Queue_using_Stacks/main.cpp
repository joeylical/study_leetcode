#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()) {
            int t;
            t = s1.top();
            s1.pop();
            s2.push(t);
        }
        int result = s2.top();
        s2.pop();
        while(!s2.empty()) {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }
        return result;
    }
    
    int peek() {
        while(!s1.empty()) {
            int t;
            t = s1.top();
            s1.pop();
            s2.push(t);
        }
        int result = s2.top();
        while(!s2.empty()) {
            int t = s2.top();
            s2.pop();
            s1.push(t);
        }
        return result;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
}
