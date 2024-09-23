#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/4sum/solutions/5790422/efficient-4-sum-solution-using-sorting-and-two-pointer-technique
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i < n;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=(i+1);j < n;j++) {
                if (j != (i+1) && nums[j] == nums[j-1]) continue;
                int k=(j+1), l=(n-1);
                while(k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum < target)k++;
                    else if(sum > target)l--;
                    else{
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l &&nums[k] == nums[k-1]) k++;
                        while(k < l &&nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return result;
                        
    }
};

int main()
{
    /* vector<int> nums = {1, 0, -1, 0, -2, 2}; */
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};

    auto result = (new Solution())->fourSum(nums, 0);

    for(auto v:result) {
        for(auto i:v)
            cout<<i<<' ';
        cout<<endl;
    }

    return 0;
}

