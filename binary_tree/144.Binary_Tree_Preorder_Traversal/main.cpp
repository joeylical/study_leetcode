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

/* class Solution { */
/* public: */
/*     vector<int> preorderTraversal(TreeNode* root) { */
/*         vector<int> result; */
/*         queue<TreeNode*> q; */
/*         if(root) */
/*             q.push(root); */
/*  */
/*         while(!q.empty()) { */
/*             auto cur = q.front(); */
/*             result.push_back(cur->val); */
/*             if(cur->left) */
/*                 q.push(cur->left); */
/*             if(cur->right) */
/*                 q.push(cur->right); */
/*             q.pop(); */
/*         } */
/*  */
/*         return result; */
/*     } */
/* }; */

/* class Solution { */
/* public: */
/*     vector<int> preorderTraversal(TreeNode* root) { */
/*         vector<int> result; */
/*         stack<TreeNode*> s; */
/*  */
/*         if(root) */
/*             s.push(root); */
/*  */
/*         while(!s.empty()) { */
/*             auto cur = s.top(); */
/*             s.pop(); */
/*             result.push_back(cur->val); */
/*             if(cur->left) */
/*                 s.push(cur->left); */
/*             if(cur->right) */
/*                 s.push(cur->right); */
/*         } */
/*  */
/*         return result; */
/*     } */
/* }; */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;

        if(root)
            s.push(root);

        while(!s.empty()) {
            auto cur = s.top();
            s.pop();
            result.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }

        return result;
    }
};

int main()
{
    TreeNode node3(3);
    TreeNode node2(2, &node3, NULL);
    TreeNode tree(1, NULL, &node2);
    auto result = (new Solution())->preorderTraversal(&tree);

    for(auto i: result) {
        cout<<i<<' ';
    }
    cout<<endl;
}
