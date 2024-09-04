#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for(int i=0;i<nums.size();i++) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution s;
    int result = s.removeElement(nums, 3);
    cout<<result<<endl;
    return 0;
}

