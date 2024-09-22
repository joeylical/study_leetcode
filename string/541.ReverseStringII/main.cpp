#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int index = 0;
        const int len = s.size() - 1;

        while(index < len) {
            int m = index;
            int n = index + k - 1;
            if (n > len)
                n = len;
            while(m < n) {
                char t = s[m];
                s[m] = s[n];
                s[n] = t;
                m++;
                n--;
            }
            index += k + k;
        }

        return s;
    }
};

int main()
{
    string s = "abcdefg";
    int k = 2;

    string result = (new Solution())->reverseStr(s, k);

    cout<<result<<endl;
    return 0;
}

