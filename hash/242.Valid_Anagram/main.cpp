#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        if(s.size() != t.size())
            return false;

        for(int i=0;i<s.size();i++) {
            char a, b;
            a = s[i];
            b = t[i];
            if(map.find(a) == map.end()) {
                map[a] = 0;
            }
            if(map.find(b) == map.end()) {
                map[b] = 0;
            }
            map[a]++;
            map[b]--;
        }

        for(auto i=map.begin();i != map.end();i++) {
            if (i->second != 0)
                return false;
        }

        return true;
    }
};


int main() {
    string s = "anagram";
    string t = "nagaram";

    std::cout<<(new Solution())->isAnagram(s, t)<<std::endl;
    return 0;
}
