#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = {0};
        for(char c:ransomNote)
            letters[c-'a']++;
        for(char c:magazine)
            letters[c-'a']--;

        int r = true;
        for(int a:letters)
            if (a>0)
                r = false;
        return r;
    }
};

int main() {
    string
        a = "aa",
        b = "ab";

    cout<<(new Solution())->canConstruct(a, b)<<endl;
    return 0;
}
