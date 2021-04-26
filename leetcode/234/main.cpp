#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * reverseList(ListNode* head) {
    auto pre = new ListNode(-1);
    pre->next = head;
    while (head->next) {
        auto tmp = head->next;
        head->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
        head = head->next;
    }
    return pre->next;
}

bool isPalindrome(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = reverseList(slow->next);
    slow->next = nullptr;
    slow = head;
    while (slow && fast)
        if (slow->val != fast->val)
            return false;
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
