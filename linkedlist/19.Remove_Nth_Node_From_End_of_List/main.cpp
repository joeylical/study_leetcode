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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode h(-1, head);
        ListNode *nhead=&h;
        head = &h;
        ListNode* slow;

        while(head && n--) {
            head = head->next;
        }
        
        slow = nhead;

        while(head->next) {
            head = head->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return nhead->next;
    }
};

int main() {
    ListNode e5(5, NULL),
             e4(4, &e5),
             e3(3, &e4),
             e2(2, &e3),
             e1(1, &e2);
    /* ListNode e2(5, NULL), */
    /*          e1(4, &e2); */
    /* ListNode e1(5, NULL); */

    ListNode *p = (new Solution())->removeNthFromEnd(&e1, 2);

    while(p) {
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;

    return 0;
}
