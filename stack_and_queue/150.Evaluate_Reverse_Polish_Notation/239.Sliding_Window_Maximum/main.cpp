#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        queue<int> q;

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

