#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归
/*
vector<int> ans;
void preorder(TreeNode * root) {
    if (root) {
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    ans.clear();
    preorder(root);
    return ans;
}
*/

//非递归
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root) {
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *cur = s.top();
            ans.push_back(cur->val);
            s.pop();
            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
    }

    return ans;
}




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
