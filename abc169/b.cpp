#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    set<ll> s;
    rep(i, n) {
        cin >> a.at(i);
        s.insert(a.at(i));
    }
    
    if(s.count(0)) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    rep(i, n) {
        if(a.at(i) <= LLONG_MAX / ans && (ans * a.at(i))/a.at(i) == ans) ans *= a.at(i);
        else {
            cout << -1 << endl;
            return 0;
        }
        if(1000000000000000000LL < ans) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}