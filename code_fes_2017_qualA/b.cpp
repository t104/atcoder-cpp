#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int n, m, k;


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int ki = i*m + j*n - 2*i*j;
            if (ki == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}