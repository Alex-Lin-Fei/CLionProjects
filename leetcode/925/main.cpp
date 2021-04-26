#include <iostream>
using namespace std;

bool isLongPressedName(string name, string typed) {
    if (typed.length() < name.length())
        return false;

    int i = 0, j = 0;
    while (i < name.length() && j < typed.length()) {
        if (name[i] != typed[j])
            return false;

        while (i < name.length() && j < typed.length() && name[i] == typed[j]) {
            i++;
            j++;
        }
        if (name[i] == name[i - 1])
            return false;
        while (j < typed.length() && typed[j] == typed[j - 1])
            j++;
    }
    return i == name.length() && j == typed.length();
}

int main() {
    std::cout <<isLongPressedName("abbcee", "abbbccceee")<< std::endl;
    return 0;
}
