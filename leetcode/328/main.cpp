#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode *pOdd = head;
    ListNode *pEven = head->next;
    ListNode *tmp = head->next;

    while (pEven->next) {
        pOdd->next = pEven->next;
        pOdd = pOdd->next;
        if (pOdd->next) {
            pEven->next = pOdd->next;
            pEven = pEven->next;
        } else {
            pEven->next= nullptr;
            break;
        }
    }
    pOdd->next = tmp;
    return head;
}


int main() {
    int n = 7;
    ListNode * head = new ListNode(1);
    ListNode* tmp = head;
    for (int i = 2; i <= n; i++) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    head = oddEvenList(head);
    while(head){
        cout << head->val<<' ';
        head=head->next;
    }


    return 0;
}
