#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
int getHeight(TreeNode* root) {
    if(!root)
        return -1;
    int h = 0;
    while (root->left) {
        h++;
        root = root->left;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if(!root)
        return 0;


    int sum = 0;

    int h = getHeight(root);
    sum += pow(2, h) - 1;
    int N = pow(2, h);

    while (root) {
        N /= 2;
        if (!root->left && !root->right) {
            sum += 1;
            break;
        }
        else if (getHeight(root->left) > getHeight(root->right)) {
            root = root->left;
        } else {
            root = root->right;
            sum += N;
        }
    }

    return sum;
}
 */

//二分法查找叶子
bool searchLeaf(TreeNode * root, int num, int h) {
    while (h--) {
        if (num & (int) pow(2, h))
            root = root->right;
        else
            root = root->left;
    }

    return root;
}



int countNodes(TreeNode* root) {
    if (!root)
        return 0;
    int sum = 0;

//    获取树的高度h
    auto tmp = root;
    int h = 0;
    while (tmp->left) {
        h++;
        tmp = tmp->left;
    }
    sum += pow(2, h) - 1;

    int l = 0;
    int r = pow(2, h) - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (searchLeaf(root, m, h))
            l = m + 1;
        else
            r = m - 1;
    }
//while (l<=r) {
//    if (searchLeaf(root, l, h))
//        l++;
//    else
//        break;
//}
    sum += l;

    return sum;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left = new TreeNode(6);


    countNodes(root);
    return 0;
}
