#include <iostream>
#include <vector>

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
    vector<string> buildPath(TreeNode* root, string path) {
        vector<string> v;
        if(!root->left && !root->right)
            return {path};
        if(root->left) {
            auto pl = buildPath(root->left, path+"->"+to_string(root->left->val));
            for(auto s:pl) {
                v.push_back(s);
            }
        }
        if(root->right) {
            auto pl = buildPath(root->right, path+"->"+to_string(root->right->val));
            for(auto s:pl) {
                v.push_back(s);
            }
        }

        return v;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return vector<string>();
        return buildPath(root, to_string(root->val));
    }
};

int main()
{
    TreeNode tree(1,
            new TreeNode(2,
                NULL,
                new TreeNode(5)),
            new TreeNode(3));

    auto result = (new Solution())->binaryTreePaths(&tree);

    for(auto l: result)
        cout<<l<<endl;
    return 0;
}

