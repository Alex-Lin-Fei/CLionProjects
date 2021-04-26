#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto * pre = new ListNode(-1);
    pre->next = head;

    ListNode * last = head;
    ListNode * first = pre;

    while(n--) {
        last=last->next;
        if(last == nullptr)
            break;
    }

    while(last){
        last = last->next;
        first = first->next;
    }
    ListNode* temp = first->next;
    first->next = temp->next;
    delete temp;
    temp = nullptr;

    return pre->next;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
