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

// not so good
/* class Solution { */
/* public: */
/*     vector<vector<int>> levelOrder(TreeNode* root) { */
/*         vector<vector<int>> result; */
/*         vector<TreeNode*>* q = new vector<TreeNode*>(); */
/*         if(root) { */
/*             q->push_back(root); */
/*         } */
/*  */
/*         while(!q->empty()) { */
/*             vector<TreeNode*> *nodes = new vector<TreeNode*>(); */
/*             vector<int> rr; */
/*             for(auto node:*q) { */
/*                 rr.push_back(node->val); */
/*                 if(node->left) */
/*                     nodes->push_back(node->left); */
/*                 if(node->right) */
/*                     nodes->push_back(node->right); */
/*             } */
/*             result.push_back(rr); */
/*             delete q; */
/*             q = nodes; */
/*         } */
/*  */
/*         return result; */
/*     } */
/* }; */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        while(!q.empty()) {
            vector<int> rr;
            // key point!
            int size = q.size();
            for(int i=0;i < size;i++) {
                auto cur = q.front();
                q.pop();
                rr.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(rr);
        }

        return result;
    }
};

int main()
{
    TreeNode node3(3);
    TreeNode node2(2, &node3, NULL);
    TreeNode tree(1, NULL, &node2);
    auto result = (new Solution())->levelOrder(&tree);

    for(auto l: result) {
        for(auto i: l) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
