#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    const int inf = 1 << 30;
    vector<int> dp(n,inf);
    dp.at(0) = 0;

    for (int i = 1; i < n; ++i) {
        dp.at(i) = dp.at(i-1) + abs(h.at(i) - h.at(i-1));
        if (2 <= i) {
            dp.at(i) = min(dp.at(i), dp.at(i-2) + abs(h.at(i) - h.at(i-2)));
        }
    }

    cout << dp.at(n-1) << endl;
    return 0;
}