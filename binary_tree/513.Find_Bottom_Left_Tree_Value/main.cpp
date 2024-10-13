#include <cstddef>
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    int findBottomLeftValue(TreeNode* root) {
        int r;
        queue<TreeNode*> q;
        if(root)
            q.push(root);

        while(!q.empty()) {
            int size = q.size();
            r = q.front()->val;
            for(int i=0;i<size;i++) {
                auto cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return r;
    }
};

int main()
{
    TreeNode tree(1,
            new TreeNode(2,
                new TreeNode(4),
                NULL),
            new TreeNode(3,
                new TreeNode(5,
                    new TreeNode(7),
                    NULL),
                new TreeNode(6)));

    auto r = Solution().findBottomLeftValue(&tree);

    cout<<r<<endl;
    return 0;
}
