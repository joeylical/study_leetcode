#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i < s.length();i++) {
            switch (s[i]) {
                case '{':
                    st.push('}');
                    break;
                case '[':
                    st.push(']');
                    break;
                case '(':
                    st.push(')');
                    break;
                case '}':
                case ']':
                case ')':
                    if(st.empty())
                        return false;
                    char c = st.top();
                    st.pop();
                    if (c != s[i])
                        return false;
            }
        }
        return st.empty();
    }
};

int main()
{
    auto s = "{[()]})";

    auto result = (new Solution())->isValid(s);

    cout<<result<<endl;
    return 0;
}

