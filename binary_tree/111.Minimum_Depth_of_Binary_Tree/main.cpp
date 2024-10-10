#include <iostream>
#include <queue>

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
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            int size = q.size();
            depth++;
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                if(!cur->left && !cur->right)
                    return depth;
            }
        }

        return depth;
    }
};

int main()
{
    TreeNode node3(3);
    TreeNode node2(2, &node3, NULL);
    TreeNode tree(1, NULL, &node2);
    auto result = (new Solution())->minDepth(&tree);

    cout<<result<<endl;
}
