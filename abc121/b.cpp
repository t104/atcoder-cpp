#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, m) cin >> b.at(i);
    rep(i, n) {
        rep(j, m) {
            cin >> a.at(i).at(j);
        }
    }

    int ans = 0;
    rep(i, n) {
        int k = 0;
        rep(j, m) {
            k +=  a.at(i).at(j) * b.at(j);
        }
        k += c;
        if(0 < k) ans++;
    }
    cout << ans << endl;
    return 0;
}