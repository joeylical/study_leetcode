#include <iostream>
#include <type_traits>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> r;

        if(root)
            q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> rr;
            for(int i=0;i<size;i++) {
                auto cur = q.front();
                q.pop();
                rr.push_back(cur->val);
                for(auto e: cur->children)
                    q.push(e);
            }
            r.push_back(rr);
        }
        return r;
    }
};

int main()
{
    Node tree(1,
            {new Node(3, {
                    new Node(5),
                    new Node(6)}),
             new Node(2),
             new Node(4)});

    auto result = (new Solution())->levelOrder(&tree);

    for(auto l: result) {
        for(auto i: l) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

