#include <iostream>

using namespace std;

class MyLinkedList {
private:
    int count;
    struct LinkedList {
        int val;
        struct LinkedList* next;
        LinkedList (int val, struct LinkedList* next): val(val), next(next) {}
    } *head;

public:
    MyLinkedList() {
        count = 0;
        head = new LinkedList(-1, NULL);
    }
    
    int get(int index) {
        if (index < 0 || index >= count)
            return -1;
        struct LinkedList* t = head;

        do {
            t = t->next;
        } while(index--);

        return t->val;
    }
    
    void addAtHead(int val) {
        struct LinkedList* t = new LinkedList(val, head->next);
        head->next = t;
        count++;
    }
    
    void addAtTail(int val) {
        struct LinkedList* t = new LinkedList(val, NULL);
        struct LinkedList* n = head;
        
        while(n->next) {
            n = n->next;
        }

        n->next = t;
        count++;
    }
    
    void addAtIndex(int index, int val) {
        struct LinkedList* t = new LinkedList(val, NULL);
        struct LinkedList* n = head;
        
        if (index > count)
            return;

        while(index--) {
            n = n->next;
        };

        t->next = n->next;
        n->next = t;
        count++;
    }
    
    void deleteAtIndex(int index) {
        struct LinkedList* n = head;
        
        if (index >= this->count)
            return;

        while(index--) {
            n = n->next;
        }

        struct LinkedList *p = n->next;
        n->next = n->next->next;
        delete p;

        count--;
    }

    void print() {
        cout<<"Items count: "<<count<<endl;
        
        int i=0;
        struct LinkedList* n = head;

        while(n) {
            cout<<n->val<<"->";
            n = n->next;
        }
        cout<<"NULL"<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    myLinkedList.print();
    myLinkedList.addAtIndex(3, 0);    // linked list becomes 1->2->3
    myLinkedList.print();
    myLinkedList.deleteAtIndex(2);    // now the linked list is 1->3
    myLinkedList.print();
    myLinkedList.addAtHead(6);
    myLinkedList.print();
    myLinkedList.addAtTail(4);
    myLinkedList.print();
    cout<<myLinkedList.get(4)<<endl;              // return 2
    myLinkedList.addAtHead(4);
    myLinkedList.addAtIndex(5, 0);    // linked list becomes 1->2->3
    myLinkedList.addAtHead(6);
    myLinkedList.print();
    return 0;
}

