#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    const int inf = 1 << 30;
    vector<int> dp(n, inf);
    dp.at(0) = 0;
    for (int i = 1; i < n; ++i) {
        for (int ki = 1; ki <= k; ++ki) {
            if (0 <= i-ki) {
                dp.at(i) = min(dp.at(i), dp.at(i-ki) + abs(h.at(i) - h.at(i-ki)));
            }
        }
    }
    cout << dp.at(n-1) << endl;
    return 0;
}