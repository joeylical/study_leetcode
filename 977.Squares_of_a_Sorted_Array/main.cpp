#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> n_nums(nums.size(), 0);
        int l = 0;
        int nl = nums[l] * nums[l];
        int r = nums.size() - 1;
        int nr = nums[r] * nums[r];
        int i = nums.size() - 1;

        for(;i > 0;i--) {
            if(nl > nr) {
                n_nums[i] = nl;
                l++;
                nl = nums[l] * nums[l];
            } else {
                n_nums[i] = nr;
                r--;
                nr = nums[r] * nums[r];
            }
        }

        if(nl > nr) {
            n_nums[i] = nl;
        } else {
            n_nums[i] = nr;
        }

        return n_nums;
    }
};

int main() {
    /* vector<int> nums = {-4,-1,0,3,10}; */
    vector<int> nums = {1};
    Solution s;
    vector<int> r = s.sortedSquares(nums);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
