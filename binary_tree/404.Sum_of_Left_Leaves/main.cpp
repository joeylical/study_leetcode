#include <ios>
#include <iostream>
#include <stack>

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        stack<TreeNode*> s;
        if(root && (root->left || root->right))
            s.push(root);

        while(!s.empty()) {
            auto cur=s.top();
            s.pop();

            if(!cur->left && !cur->right) {
                sum += cur->val;
            }
            if(cur->left) {
                s.push(cur->left);
            }
            if(cur->right) {
                if(cur->right->left || cur->right->right) {
                    s.push(cur->right);
                }
            }
        }

        return sum;
    }
};

int main()
{
    TreeNode tree(3,
            new TreeNode(9),
            new TreeNode(20,
                new TreeNode(15),
                new TreeNode(7)));

    int sum = (new Solution())->sumOfLeftLeaves(&tree);

    cout<<sum<<endl;
    return 0;
}
