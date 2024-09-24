#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                switch(token[0]) {
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
                }
                st.push(a);
            } else {
                int a = stoi(token);
                st.push(a);
            }
        }

        return st.top();
    }
};

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    int result = (new Solution())->evalRPN(tokens);

    cout<<result<<endl;
    return 0;
}

