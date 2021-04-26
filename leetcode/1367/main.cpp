#include <iostream>
using namespace std;


struct ListNode {
    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode() : val(0), left(nullptr), right(nullptr) {}

     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 bool recur(ListNode* head, TreeNode* root) {
     if (!head)return true;
     if (!root)return false;
     if (root->val != head->val)return false;
     return recur(head->next, root->left) || recur(head->next,root->right);
 }

 bool isSubPath(ListNode* head, TreeNode* root) {
     return root && (isSubPath(head, root->left) || isSubPath(head, root->right) || recur(head, root));
 }

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
