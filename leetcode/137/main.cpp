#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    vector<int> v{2,2,3,2};
    int seen_once = 0;
    int seen_two = 0;
    for (auto & i: v) {
        cout << "I: " << bitset<8>(i) << endl;
        seen_once = ~seen_two & (seen_once ^ i);
        seen_two = ~seen_once & (seen_two ^ i);
        cout << "seen_once: " << bitset<8>(seen_once) << endl;
        cout << "seen_two: " << bitset<8>(seen_two) << endl;

    }
    cout << "seen_once: " << bitset<8>(seen_once) << endl;

    return 0;
}
