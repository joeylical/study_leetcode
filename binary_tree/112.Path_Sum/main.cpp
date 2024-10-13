#include <cstddef>
#include <iostream>

using namespace std;

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;

        targetSum -= root->val;

        return (!root->left && !root->right && !targetSum)    ||
            (root->left && hasPathSum(root->left, targetSum)) ||
            (root->right && hasPathSum(root->right, targetSum));
    }
};

int main()
{
    TreeNode tree(5,
            new TreeNode(4,
                new TreeNode(11,
                    new TreeNode(7),
                    new TreeNode(2)),
                NULL),
            new TreeNode(8,
                new TreeNode(13),
                new TreeNode(4,
                    NULL,
                    new TreeNode(1))));

    auto r = Solution().hasPathSum(&tree, 22);

    cout<<r<<endl;
    return 0;
}

