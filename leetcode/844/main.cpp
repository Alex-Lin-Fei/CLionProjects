#include <iostream>
#include <stack>
using namespace std;

void inStack(stack<char> & s, string str) {
    for(auto& ch: str)
    {
        if(ch == '#') {
            if (!s.empty())
                s.pop();
        }
        else
            s.push(ch);
    }
}

bool backspaceCompare(string S, string T) {
    stack<char> stackS, stackT;

    inStack(stackS, S);
    inStack(stackT, T);

    if (stackS.empty() && stackT.empty())
        return true;

    if (stackT.size() == stackS.size()) {
        while (!stackS.empty() && !stackT.empty()) {
            if (stackS.top() != stackT.empty())
                return false;
        }
        return true;
    }

    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
