#include <iostream>
#include <vector>

using namespace std;

// KMP alg
// https://oi-wiki.org/string/kmp/
// https://www.grubwithu.icu/2023/07/04/kmp/index.html
// next 每个值记录当前位置的后缀和前缀相等的长度
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.length());

        int j = 0;

        for(int i=1;i < needle.length();i++) {
            j = next[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                // why j = next[j - 1]?
                // continunous same characters
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
                j++;
            next[i] = j;
        }

        /*
        for(auto c:needle)
            cout<<c<<' ';
        cout<<endl;
        for(auto i:next)
            cout<<i<<' ';
        cout<<endl;
        //*/
        
        j = 0;
        for(int i=0;i <= haystack.length();i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            if(haystack[i] == needle[j]) {
                j++;
                if (j == needle.length()) {
                    return i - needle.length() + 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    string haystack = "missississipi";
    string needle = "aabaaab";

    int pos = (new Solution())->strStr(haystack, needle);

    cout<<pos<<endl;
    return 0;
}
