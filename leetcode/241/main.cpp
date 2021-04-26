#include <iostream>
#include <vector>
using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> ans;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]))
            continue;
        else {
            vector<int> leftNum = diffWaysToCompute(input.substr(0, i));
            vector<int> rightNum = diffWaysToCompute(input.substr(i + 1, input.length() - i));
            for (auto &l: leftNum)
                for (auto &r: rightNum) {
                    switch (input[i]) {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                    }
                }
        }
    }
    if (ans.empty())
        ans.push_back(stoi(input));
    return ans;
}

int main() {
    vector<int> ans = diffWaysToCompute("2-1-1");
    for(auto & i: ans)
    std::cout << i << std::endl;
    return 0;
}
