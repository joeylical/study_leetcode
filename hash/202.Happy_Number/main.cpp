#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> r;

        while(1) {
            int rr=0;
            while(n) {
                int digit = n % 10;
                rr += digit * digit;
                n /= 10;
            }
            n = rr;
            if(n == 1)
                return true;
            if(r.count(n))
                return false;
            r.insert(n);
        }
    }
};

int main() {
    cout<<(new Solution())->isHappy(19)<<endl;
    return 0;
}
