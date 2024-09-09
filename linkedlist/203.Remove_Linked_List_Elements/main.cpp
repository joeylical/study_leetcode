#include <iostream>

using namespace std;

 // Definition for singly-linked list.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nhead = head;
        ListNode* last = NULL;

        while (head) {
            if (head->val == val) {
                if(last) {
                    last->next = head->next;
                } else {
                    nhead = head->next;
                }
            } else
                last = head;
            head = head->next;
        }

        return nhead;
    }
};

int main() {
    struct ListNode e4(7, NULL);
    struct ListNode e3(7, &e4);
    struct ListNode e2(7, &e3);
    struct ListNode e1(7, &e2);

    cout<<&e1<<endl<<&e2<<endl<<&e3<<endl<<&e4<<endl;
    
    struct ListNode* head = (new Solution())->removeElements(&e1, 7);

    cout<<endl<<endl;

    while(head) {
        cout<<head->val<<' '<<head->next<<endl;
        head = head->next;
    }
}

