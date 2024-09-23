#include <iostream>
#include <vector>

using namespace std;

// https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
// 目标字符串s为周期字符串!!!
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int len = s.length();
        vector<int> next(len);

        int j=0;
        for(int i=1;i < len;i++) {
            j = next[i - 1];
            
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }

            if (s[i] == s[j])
                j++;

            next[i] = j;
        }

        /* for(auto i:next) */
        /*     cout<<i<<' '; */
        /* cout<<endl; */

        return next[len - 1] && len % (len - next[len - 1]) == 0;
    }
};

int main()
{
    string s = "a";

    bool result = (new Solution())->repeatedSubstringPattern(s);

    cout<<result<<endl;
    return 0;

}
