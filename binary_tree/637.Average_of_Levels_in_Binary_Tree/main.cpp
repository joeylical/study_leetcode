#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            double sum = 0;
            int size = q.size();
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(sum/size);
        }

        return result;
    }
};

int main()
{
    TreeNode node3(3);
    TreeNode node2(2, &node3, NULL);
    TreeNode tree(1, NULL, &node2);
    auto result = (new Solution())->averageOfLevels(&tree);

    for(auto i: result) {
        cout<<i<<' ';
    }
    cout<<endl;
}
