#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a={nums1.begin(), nums1.end()};
        unordered_set<int> rr;

        for(auto i=nums2.begin();i != nums2.end();i++) {
            if(a.count(*i)) {
                rr.insert(*i);
            }
        }

        return *new vector<int>(rr.begin(), rr.end());
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> r = (new Solution())->intersection(nums1, nums2);

    for(auto i=r.begin();i != r.end();i++) {
        cout<<*i<<endl;
    }
    return 0;
}
