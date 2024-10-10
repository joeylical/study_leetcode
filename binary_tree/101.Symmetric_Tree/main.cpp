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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        if(q.size() == 0)
            return true;
        if(q.size() != 2)
            return false;

        while(!q.empty()) {
            int size = q.size();
            vector<TreeNode*> v(size/2);
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                if(i<size/2)
                    v[i] = cur;
                else{
                    auto sym = v[size-i-1];
                    if(sym){
                        if(!cur)
                            return false;
                        if(sym->val != cur->val){
                            return false;
                        }
                    }else if(cur)
                        return false;
                }
                if(cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }

        return true;
    }
};

int main()
{
    /* TreeNode tree(1, */
    /*         new TreeNode(2, */
    /*             new TreeNode(3), */
    /*             new TreeNode(4)), */
    /*         new TreeNode(2, */
    /*             new TreeNode(4), */
    /*             new TreeNode(3))); */
    TreeNode tree(2,
            new TreeNode(3,
                new TreeNode(4),
                new TreeNode(5)),
            new TreeNode(3,
                new TreeNode(5),
                NULL));
    auto result = (new Solution())->isSymmetric(&tree);

    cout<<result<<endl;
}
