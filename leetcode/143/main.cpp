#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//recursion
/*
ListNode * Nex(ListNode * head) {
    if(head && head->next) {
        ListNode *last = head->next;
        ListNode *preLast = head;
        while (last->next) {
            last = last->next;
            preLast = preLast->next;
        }
        if(preLast == head)
            return head;
        last->next = head->next;
        head->next = last;
        preLast->next = nullptr;
        last->next = Nex(last->next);
        return head;
    }

    return head;
}
*/

ListNode* ReverseList(ListNode * head) {
    auto preH = new ListNode(-1);
    preH->next = head;

    ListNode *last = head;
    while (last->next) {
        ListNode *tmp = last->next;
        last->next = tmp->next;
        tmp->next = preH->next;
        preH->next = tmp;
    }

    return preH->next;
}


void reorderList(ListNode* head) {
//    head = Nex(head);
    if (!head || !head->next)
        return;
    ListNode *fast = head;
    ListNode *slow = head;


    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = ReverseList(slow->next);
    slow->next = nullptr;
    auto *pre = new ListNode(-1);
    slow = head;

    while (fast && slow) {
        pre->next = slow;
        slow = slow->next;
        pre = pre->next;
        pre->next = fast;
        fast = fast->next;
        pre = pre->next;
    }
    if(slow)
        pre->next = slow;
}

int main() {
    auto * head = new ListNode(1);
    int idx = 2;
    ListNode * pre = head;

    while(idx<=5) {
        pre->next = new ListNode(idx);
        idx++;
        pre = pre->next;
    }
    reorderList(head);
    while(head) {
        cout << head->val << ' ';
        head=head->next;
    }


    return 0;
}
