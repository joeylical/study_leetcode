#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //review: https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i=0;i < nums.size();i++) {
            if(nums[i] > 0)
                return result;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
    /* vector<int> nums = {0, 1, 1}; */
    /* vector<int> nums = {-1, 0, 1, 2, -1, -4}; */
    vector<int> nums = {-2, 0, 1, 1, 2};

    vector<vector<int>> result = (new Solution())->threeSum(nums);

    for(auto v:result) {
        for(int i: v) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}
