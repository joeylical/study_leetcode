#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;
        vector<int> result;

        for(int i=0;i<nums.size();i++) {
            if(res.count(target - nums[i])){
                return *new vector<int>() = {res[target-nums[i]], i};
            }
            res[nums[i]] = i;
        }
        return *new vector<int>();
    }
};

int main() {
    vector<int> nums={2,7,11,15};

    vector<int> r = (new Solution())->twoSum(nums, 9);

    cout<<r[0]<<' '<<r[1]<<endl;
    return 0;
}

