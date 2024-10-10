#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                auto t = cur->left;
                cur->left = cur->right;
                cur->right = t;
            }
        }

        return root;
    }
};

void print(TreeNode* root)
{
    queue<TreeNode*> q;
    if(root) {
        q.push(root);
    }

    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i < size;i++) {
            auto cur = q.front();
            q.pop();
            cout<<cur->val<<' ';
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }

    cout<<endl;
}

int main()
{
    TreeNode tree(4,
            new TreeNode(2,
                new TreeNode(1),
                new TreeNode(3)),
            new TreeNode(7,
                new TreeNode(6),
                new TreeNode(9)));

    print(&tree);
    auto r = (new Solution())->invertTree(&tree);
    print(r);
    return 0;

}

