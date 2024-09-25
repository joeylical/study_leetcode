#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        // pair is much faster than vector
        auto cmp = [](pair<int, int> a, pair<int, int> b){return a.second < b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> t(cmp);
        
        for(int i: nums) {
            s[i]++;
        }

        for(auto i: s) {
            t.push({i.first, i.second});
        }

        vector<int> r;
        for(int i=0;i< k;i++) {
            r.push_back(t.top().first);
            t.pop();
        }

        return r;
    }
};

int main()
{
    vector<int> nums = {1,1,1,2,2,3};

    auto result = (new Solution())->topKFrequent(nums, 2);

    for(auto i: result)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}

