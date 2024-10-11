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
public:
    int countNodes(TreeNode* root) {
        int sumLevel = 1;
        int level = 1;
        int full = 1;
        auto cur = root;
        if(!root)
            return 0;
        while(cur->left) {
            sumLevel<<=1;
            full += sumLevel;
            level++;
            cur = cur->left;
        }

        if(level == 1)
            return 1;

        int min = 0;
        int max = sumLevel-1;
        int last_i=0;
        while(min <= max) {
            int mid = (max+min)/2;
            cur = root;
            for(int l=0;l<level-1;l++) {
                if(mid&1<<(level-2)){
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
                mid<<=1;
            }
            mid = (max+min)/2;
            if(cur) {
                min = mid + 1;
                last_i = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return full - sumLevel + last_i;
    }
};

int main()
{
    TreeNode tree(1,
            new TreeNode(2,
                new TreeNode(4),
                new TreeNode(5)),
            new TreeNode(3,
                new TreeNode(6),
                NULL));
    TreeNode tree1(1,
            new TreeNode(2,
                new TreeNode(4),
                // NULL, 
                NULL),
            new TreeNode(3,
                NULL,
                NULL));
    TreeNode tree2(1,
            new TreeNode(2,
                NULL, 
                NULL),
            NULL);

    int result = (new Solution())->countNodes(&tree);
    cout<<result<<endl;
    result = (new Solution())->countNodes(&tree1);
    cout<<result<<endl;
    result = (new Solution())->countNodes(&tree2);
    cout<<result<<endl;

    return 0;
}

