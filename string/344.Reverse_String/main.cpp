#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0;
        int last = s.size() - 1;
        char t;

        while(first < last) {
            t = s[first];
            s[first] = s[last];
            s[last] = t;
            first++;
            last--;
        }
    }
};

int main() {
    vector<char> s={'h', 'e', 'l', 'l', 'o'};

    (new Solution())->reverseString(s);

    for(int i=0;i<s.size();i++) {
        cout<<s[i];
    }

    cout<<endl;
}

