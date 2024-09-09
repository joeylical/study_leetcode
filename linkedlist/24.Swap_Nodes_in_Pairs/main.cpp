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
    ListNode* swapPairs(ListNode* head) {
        ListNode *t, *nhead=head, *last;
        bool first=true;

        while(head && head->next) {
            t = head->next->next;
            head->next->next = head;
            if(first) {
                nhead = head->next;
                first = false;
            } else {
                last->next = head->next;
            }
            head->next = t;
            last = head;
            head = t;
        }

        return nhead;
    }
};

int main() {
    ListNode e3(3, NULL), e2(2, &e3), e1(1, &e2);
    /* ListNode e4(4, NULL), e3(3, &e4), e2(2, &e3), e1(1, &e2); */
    ListNode* p = (new Solution())->swapPairs(&e1);

    while(p) {
        cout<<p->val<<"->";
        p = p->next;
    }
    
    cout<<endl;

    return 0;
}

