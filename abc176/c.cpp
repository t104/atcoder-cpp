#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    int a_max = 0;
    ll ans = 0;
    rep(i,n) {
        a_max = max(a_max, a.at(i));
        if (a.at(i) < a_max) ans += (ll) a_max - a.at(i);
    }
    cout << ans << endl;
    return 0;
}