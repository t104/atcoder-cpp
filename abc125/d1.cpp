#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int inf = (1<<29);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<vector<ll>> dp(n+1,vector<ll>(2));
    dp.at(0).at(1) = -inf;
    rep(i,n) {
        dp.at(i+1).at(0) = max(dp.at(i).at(0) + a.at(i), dp.at(i).at(1) - a.at(i));
        dp.at(i+1).at(1) = max(dp.at(i).at(0) -  a.at(i), dp.at(i).at(1) + a.at(i));
    }
    // cout << dp.at(n).at(0) << endl;

    rep(i,n+1) {
        cout << dp.at(i).at(0) << ' ' << dp.at(i).at(1) << endl;
    }
    return 0;
}