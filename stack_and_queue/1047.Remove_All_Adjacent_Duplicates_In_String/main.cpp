#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i=0;i < s.length();i++) {
            if(!st.empty() && s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string result;
        result.resize(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            result[i--] = st.top();
            st.pop();
        }
        return result;
    }
};

int main()
{
    auto s = "abbaca";
    auto result = (new Solution())->removeDuplicates(s);
    cout<<result<<endl;
    return 0;
}
