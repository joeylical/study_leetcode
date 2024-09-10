#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // review: https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
        /******************************
         * 假设链表存在环，无环的部分长度为a，有环的部分长度为b
         * 快指针每次移动2，慢指针每次移动1
         * m步后，快指针移动了2m，快指针在环中的位置是2m-a mod b
         *        慢指针移动了m，慢指针在环中的位置是m-a mod b
         * 取m=nb，有2m-a=2nb-a，m-a=nb-a
         *         易得2nb-a≡nb-a (mod b)
         * 所以快慢指针必然相遇，且相遇的位置为nb-a，再移动a步即为环起始位置。
         * 同时环起始位置距离链表头也为a，所以可以同时从相遇位置和链表头移动，找到相遇位置即为环起始位置。
         *****************************/
        ListNode *fast=head, *slow=head;
        while (fast) {
            if(fast->next)
                fast = fast->next->next;
            else
                return NULL;
            slow = slow->next;
            if (fast == slow) {
                ListNode *a=head, *b=fast;
                while(a != b) {
                    a = a->next;
                    b = b->next;
                }
                return a;
            }
        }
        return NULL;
    }
};

int main() {
    ListNode e1(-4, NULL),
             e2(0, &e1),
             e3(2, &e2),
             e4(3, &e3);
    e1.next = &e3;

    ListNode *p = (new Solution())->detectCycle(&e4);

    cout<<p->val<<endl;
    return 0;
}
