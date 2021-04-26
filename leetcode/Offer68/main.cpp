#include <iostream>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur = root;

    while (true) {
        if (p->val < cur->val && q->val < cur->val)
            cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val)
            cur = cur->right;
        else
            break;
    }

    return cur;
}


int main() {
    int i = -1;
    int j = 6;
    if(i< j)
        cout <<"cin";
    return 0;
}
