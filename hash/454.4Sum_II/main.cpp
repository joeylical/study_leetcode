#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //review: https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html
        unordered_map<int, int> a;

        for(int i: nums1)
            for(int j: nums2)
                a[i+j]++;

        int r = 0;

        for(int i: nums3)
            for(int j: nums4) {
                int rr = 0 - i - j;
                if(a.find(rr) != a.end())
                    r += a[rr];
            }

        return r;
    }
};

int main() {
    vector<int>
        nums1 = {1, 2},
        nums2 = {-2, -1},
        nums3 = {-1, 2},
        nums4 = {0, 2};

    cout<<(new Solution())->fourSumCount(nums1, nums2, nums3, nums4)<<endl;
    return 0;
}
