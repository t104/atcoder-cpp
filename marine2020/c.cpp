#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k+1, vector<int>(n));
    rep(i, n) {
        cin >> a.at(1).at(i);
    }

    if(18 <= k || pow(2, k) > n + 1) {
        rep(i, n-1) {
            cout << n << ' ';
        }
        cout << n << endl;
        return 0;
    }

    for(int i = 2; i < k; i++) {
        rep(j, n) {
            for(int h = a.at(i-2) + 1; h <= a.at(i-1))
        }
    }

    rep(i,n-1) {
        cout << a.at(k).at(i) << ' ';
    }
    cout << a.at(k).at(n-1) << endl;

    return 0;
}