#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
const int N_MAX = 1e7 + 5;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int m = 0;
    for (int i = 1; i < N_MAX; ++i) {
        sum += i;
        if (n <= sum) {
            m = i;
            break;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i == sum - n) continue;
        cout << i << endl;
    }
    return 0;
}