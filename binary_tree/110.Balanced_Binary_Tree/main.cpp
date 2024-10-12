#include <iostream>
#include <queue>
#include <type_traits>

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
    int getDepth(TreeNode* root) {
        int dl=0, dr=0;

        if(root->left)
            dl = 1 + getDepth(root->left);
        if(root->right)
            dr = 1 + getDepth(root->right);

        return dl>dr?dl:dr;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool l,r;
        int ld=0,rd=0;
        if(root->left)
            l = isBalanced(root->left);
        if(!l)
            return false;
        if(root->right)
            r = isBalanced(root->right);
        if(!r)
            return false;
        if(root->left)
            ld = 1 + getDepth(root->left);
        if(root->right)
            rd = 1 + getDepth(root->right);

        return abs(ld-rd) <= 1;
    }
};

void print(TreeNode* root)
{
    queue<TreeNode*> q;
    if(root)
        q.push(root);

    cout<<"=====Tree====="<<endl;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            auto cur = q.front();
            q.pop();
            cout<<cur->val<<' ';
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout<<endl;
    }
    cout<<"=============="<<endl;
}

int main()
{
    TreeNode tree(1,
            new TreeNode(2,
                new TreeNode(4,
                    new TreeNode(8),
                    NULL),
                new TreeNode(5)),
            new TreeNode(3,
                new TreeNode(6),
                NULL));
    TreeNode tree1(1,
            NULL,
            new TreeNode(2,
                NULL,
                new TreeNode(3)));
    TreeNode tree2(1,
            new TreeNode(2,
                NULL, 
                NULL),
            NULL);

    print(&tree);
    int result = (new Solution())->isBalanced(&tree);
    cout<<result<<endl;
    print(&tree1);
    result = (new Solution())->isBalanced(&tree1);
    cout<<result<<endl;
    /* result = (new Solution())->isBalanced(&tree2); */
    /* cout<<result<<endl; */

    return 0;
}

