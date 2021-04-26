#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left{};
    struct TreeNode *right{};
    explicit TreeNode(int val): val{val}, left{nullptr}, right{nullptr}{

    }
};



bool isValidBST(struct TreeNode* root) {
    if (!root)
        return true;

//    左右子树均为bst
    if(!isValidBST(root->left) || !isValidBST(root->right))
        return false;

//    左边节点均小于root
    if (root->left) {
        auto tmp = root->left;
        while (tmp->right)
            tmp = tmp->right;
        if (tmp->val >= root->val)
            return false;

    } if (root->right) {
        auto tmp = root->right;
        while (tmp->left)
            tmp = tmp->left;
        if (tmp->val <= root->val)
            return false;
        cout << tmp->val<<endl;
    }

    return true;
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(28);


    std::cout << isValidBST(root) << std::endl;
    return 0;
}
