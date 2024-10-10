#include <iostream>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            int max = q.front()->val;
            int size = q.size();
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                if(cur->val > max)
                    max = cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(max);
        }

        return result;
    }
};

int main()
{
    TreeNode tree(1,
                new TreeNode(3, 
                    new TreeNode(5),
                    new TreeNode(3)
                ),
                new TreeNode(2,
                    NULL,
                    new TreeNode(9)
                ));
    auto result = (new Solution())->largestValues(&tree);

    for(auto i: result) {
        cout<<i<<' ';
    }
    cout<<endl;
}
