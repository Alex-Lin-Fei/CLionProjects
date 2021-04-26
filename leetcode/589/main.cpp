#include <iostream>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> ans;
//辅函数
void dfs(Node * root) {
    if (root) {
        ans.push_back(root->val);
        for (auto pr: root->children)
            dfs(pr);
    }
}

vector<int> preorder(Node* root) {
    ans.clear();

    dfs(root);

    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
