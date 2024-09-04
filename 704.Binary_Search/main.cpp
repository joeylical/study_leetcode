#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        while(end > begin) {
            int half = ((end - begin) >> 1) + begin;
            int num = nums[half];
            if (half == begin) {
                return (num == target) - 1;
            } else {
                if (num > target) {
                    end = half;
                    continue;
                } else if (num < target) {
                    begin = half;
                    continue;
                } else {
                    return half;
                }
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution s;
    int result = s.search(nums, 9);
    std::cout<<result<<std::endl;
    return 0;
}

