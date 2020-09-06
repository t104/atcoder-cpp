#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    const int inf = 1 << 30;
    vector<vector<int>> a(n, vector<int>(3)), dp(n,vector<int>(3, -inf));
    rep(i,n) rep(j,3) cin >> a.at(i).at(j);
    dp.at(0) = a.at(0);
    for (int i = 1; i < n; ++i) {
        dp.at(i).at(0) = max(dp.at(i-1).at(1), dp.at(i-1).at(2)) + a.at(i).at(0);
        dp.at(i).at(1) = max(dp.at(i-1).at(2), dp.at(i-1).at(0)) + a.at(i).at(1);
        dp.at(i).at(2) = max(dp.at(i-1).at(0), dp.at(i-1).at(1)) + a.at(i).at(2);
    }
    cout << *max_element(dp.at(n-1).begin(), dp.at(n-1).end()) << endl;
    return 0;
}