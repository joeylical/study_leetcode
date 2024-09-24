#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // simple but not fast enough
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int top = 0;

        for(int i=1;i < k;i++) {
            if(nums[top] < nums[i]) {
                top = i;
            }
        }
        
        for(int i=0;i < nums.size() - k + 1;i++) {
            // new item in, update max index
            if(nums[top] <= nums[i+k-1]) {
                top = i + k - 1;
            }
            result.push_back(nums[top]);
            // max number will move out
            if(i == top) {
                top = i+1;
                for(int j=0;j<k && i+1+j<nums.size();j++) {
                    if(nums[top] < nums[i+1+j])
                        top = i+1+j;
                }
            } 
        }

        return result;
    }
};

int main()
{
    /* vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7}; */
    vector<int> nums = {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};

    auto result = (new Solution())->maxSlidingWindow(nums, 7);

    for(auto i: result)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}

