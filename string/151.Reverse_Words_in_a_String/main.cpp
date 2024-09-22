#include <iostream>

using namespace std;
//ugly but work
class Solution {
public:
    string reverseWords(string s) {
        int m = 0;
        int len = s.size() - 1;
        int n = len;

        while(m < n) {
            char t = s[m];
            s[m] = s[n];
            s[n] = t;
            m++;
            n--;
        }

        m = 0;
        n = 0;
        while(s[m] == ' ') {
            m++;
        }
        n = m;
        while(m < len) {
            while(s[n+1] != ' ' && n < len) n++;
            int tn = n;
            while(m < n) {
                char t = s[m];
                s[m] = s[n];
                s[n] = t;
                m++;
                n--;
            }
            m = tn+1;
            while(s[m] == ' ') m++;
            n = m;
        }

        m = 0;
        n = 0;
        while(s[n] == ' ')n++;
        while(s[len] == ' ') len--;
        while(n <= len) {
            s[m] = s[n];
            m++;
            if (s[n] == ' ')
                do{
                    n++;
                }while(s[n] == ' ' && n < len);
            else
                n++;
        }

        s.resize(m);

        return s;
    }
};

int main()
{
    /* string s = "the  sky is blue"; */
    string s = "  hello world  ";

    string r = (new Solution())->reverseWords(s);

    cout<<r<<'|'<<endl;

    return 0;
}

