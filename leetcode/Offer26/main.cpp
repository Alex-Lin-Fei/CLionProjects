#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasFind(TreeNode * A, TreeNode* B) {
    if (!B)
        return true;
    else if (!A || A->val != B->val)
        return false;
    return (hasFind(A->left, B->left) && hasFind(A->right, B->right));
}


bool isSubStructure(TreeNode* A, TreeNode* B) {
    return (A && B && (isSubStructure(A->left, B) || isSubStructure(A->right, B) || hasFind(A, B)));
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
