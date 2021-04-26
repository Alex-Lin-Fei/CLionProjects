#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         explicit ListNode(int x) : val(x), next(nullptr) {}
     };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2)
        return nullptr;
    else if (!l1 || !l2)
        return l1? l1:l2;

    auto p1 = l1, p2 = l2;
    int c = 0;
    auto pre1 = l1, pre2 = l2;
    p1->val += p2->val;
    c = p1->val/10;
    p1->val %= 10;
    p1=p1->next;
    p2 = p2->next;

    while (p1 && p2) {
        int tmp = p1->val + p2->val + c;
        p1->val = tmp % 10;
        c = tmp / 10;
        pre1 = pre1->next;
        pre2 = pre2->next;
        p1 = p1->next;
        p2 = p2->next;
    }

    if (!p1) {
        pre1->next = pre2->next;
        p1 = pre1->next;
    }


    while (p1) {
        p1->val += c;
        c = p1->val / 10;
        p1->val %= 10;
        if (!c)
            break;
        pre1=pre1->next;
        p1 = p1->next;
    }

    if (c)
        pre1->next = new ListNode(c);
    return l1;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
