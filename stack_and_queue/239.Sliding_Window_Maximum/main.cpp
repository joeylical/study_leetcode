#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;

        for(int i=0;i < k;i++) {
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        
        for(int i=0;i < nums.size() - k + 1;i++) {
            // new item in, update max index
            while(!q.empty() && nums[q.back()] <= nums[i+k-1]) q.pop_back();
            q.push_back(i+k-1);
            int top = q.front();
            result.push_back(nums[top]);
            // max number will move out
            if(i == top) {
                q.pop_front();
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

