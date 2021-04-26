#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int gcd(int a,int b) {
    if (b > a)
        swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

//dfs
/*
int record;
vector<bool> visited;
int dfs(int cur, vector<vector<int>> & edges) {
    visited[cur] = true;

    for (auto &i: edges[cur])
        if (!visited[i])
            dfs(i, edges);
    record++;
    return record;
}

int largestComponentSize(vector<int>& A) {
    vector<vector<int>> edges(A.size());
    visited.clear();
    visited.resize(A.size());
    int ans = 0;
//    get edge
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
            if (gcd(A[i], A[j]) != 1) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }

//    check edges
    for (int i = 0; i < A.size(); i++) {
        cout << i <<": ";
        for (auto j : edges[i])
            cout <<j<<' ';
        cout << endl;
    }



//   dfs
    for (int i = 0; i < A.size(); i++) {
        if (!visited[i])
            dfs(i, edges);
        ans = max(ans, record);
        record = 0;
    }

    return ans;
}
*/

//并查集

vector<int> father, height;

void init(int n) {
    father.clear();
    father.resize(n);
    height.clear();
    height.resize(n, 0);
    for (int i = 0; i < n; i++)
        father[i] = i;
}

int findFather(int a) {
    if (a != father[a])
        father[a] = findFather(father[a]);
    return father[a];
}

bool isSame(int a, int b){
    return findFather(a) == findFather(b);
}

void unite(int a, int b) {
    a = findFather(a);
    b = findFather(b);

    if (height[a] < height[b])
        father[a] = b;
    else {
        father[b] = a;
        if (height[a] == height[b])
            height[a]++;
    }
}

/*
int largestComponentSize(vector<int>& A) {
    //    get edge
    vector<pair<int, int>> edges;
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
            if (gcd(A[i], A[j]) != 1) {
                edges.emplace_back(i, j);
//                cout<<A[i]<<' '<<A[j]<<endl;
            }


    init(A.size());
    for (auto &edge: edges)
        if (!isSame(edge.first, edge.second))
            unite(edge.first, edge.second);


    map<int, int> record;
    for (int i = 0; i < A.size(); i++)
        record[findFather(i)]++;

    int ans = 0;
    for (auto & iter : record)
        ans = max(ans, iter.second);

    return ans;
}
*/
/*
int largestComponentSize(vector<int>& A) {
//    埃式筛选法
    int N = *max_element(A.begin(), A.end());
//    cout << N<<endl;
    vector<bool> isPrime(N+1, true);
    vector<int> primes;
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
//            cout << i << '*';
            for(int j = 2 * i; j <= N; j+=i)
                isPrime[j] = false;
        }
    }
//    cout <<endl;


    init(A.size()+primes.size());

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < primes.size(); j++) {
            if (A[i] % primes[j] == 0)
                unite(j + A.size(), i);
        }
    }


    map<int, int> record;
    for (int i = 0; i < A.size(); i++) {
        cout << i <<": "<<findFather(i)<<endl;
        record[findFather(i)]++;
    }

    int ans = 0;
    for (auto & iter : record)
        ans = max(ans, iter.second);

    return ans;
}



*/
int largestComponentSize(vector<int>& A) {
//    埃式筛选法
    int N = *max_element(A.begin(), A.end());
//    cout << N<<endl;
    vector<bool> isPrime(N+1, true);
    vector<bool> isCandidate(N+1, false);

    for(auto& i: A)
        isCandidate[i] = true;

    init(N+1);
    for(int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            int t = isCandidate[i] ? i : -1;
            for (int j = i + i; j <= N; j += i) {
                if (isCandidate[j]) {
                    if (t == -1) {
                        t = j;
                    } else {
                        unite(t, j);
                    }
                }
                isPrime[j] = false;
            }
        }
    }

    map<int, int> record;
    for (int i = 0; i < A.size(); i++) {
        cout << i <<": "<<findFather(A[i])<<endl;
        record[findFather(A[i])]++;
    }

    int ans = 0;
    for (auto & iter : record)
        ans = max(ans, iter.second);

    return ans;
}

int main() {
    vector<int> A{65, 35, 43, 76, 15, 11, 81, 22, 55, 92, 31};
    cout << largestComponentSize(A);
    return 0;
}
