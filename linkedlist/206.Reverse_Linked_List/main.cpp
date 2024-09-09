#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t;
        ListNode* last=NULL;

        while(head) {
            t = head->next;
            head->next = last;
            last = head;
            head = t;
        }

        return last;
    }
};

int main() {
    ListNode e5(5, NULL);
    ListNode e4(4, &e5);
    ListNode e3(3, &e4);
    ListNode e2(2, &e3);
    ListNode e1(1, &e2);

    ListNode* p = (new Solution())->reverseList(&e1);

    while(p) {
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;

    return 0;
}

