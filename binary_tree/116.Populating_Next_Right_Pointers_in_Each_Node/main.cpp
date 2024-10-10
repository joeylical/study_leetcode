#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root)
            q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto cur = q.front();
                q.pop();
                if(i<size-1)
                    cur->next = q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }

        return root;
    }
};

int main()
{
    Node tree(1,
            new Node(2,
                new Node(4),
                new Node(5),
                NULL),
            new Node(3,
                new Node(6),
                new Node(7),
                NULL), NULL);

    auto result = (new Solution())->connect(&tree);

}

