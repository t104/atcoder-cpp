#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(3*n);
    rep(i, 3*n) cin >> a.at(i);
    ll ans = 0;
    sort(a.rbegin(), a.rend());
    rep(i,n) {
        ans += a.at(1 + 2*i);
    }
    cout << ans << endl;
    return 0;
}