#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i,2) rep(j,n) cin >> a.at(i).at(j);

    int ans = 0, sum = 0;
    rep(i,n) sum += a.at(0).at(i);
    sum += a.at(1).at(n-1);
    ans = max(ans, sum);
    for (int i = n-1; 0 < i; --i) {
        sum -= a.at(0).at(i);
        sum += a.at(1).at(i-1);
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}