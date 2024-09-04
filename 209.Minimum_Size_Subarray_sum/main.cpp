#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int min_len = 0;

        while (i < nums.size()) {
            while (sum < target && i + j < nums.size()) {
                sum += nums[i+j];
                j++;
            }
            if (sum < target) {
                break;
            } else if(!min_len || min_len > j) {
                min_len = j;
            }
            sum -= nums[i];
            i++;
            j--;
        }

        return min_len;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    cout<<s.minSubArrayLen(11, nums)<<endl;
    vector<int> nums1 = {2,3,1,2,4,3};
    cout<<s.minSubArrayLen(7, nums1)<<endl;
    return 0;
}

