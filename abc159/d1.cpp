#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll choose2(ll n) {
    return n*(n-1)/2;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) a.at(i)--;
    vector<int> cnt(n);
    rep(i,n) cnt.at(a.at(i))++;
    ll tot = 0;
    rep(i,n) tot += (long) cnt.at(i)*(cnt.at(i) - 1)/2;
    rep(i,n) {
        ll ans = tot;
        ans -= cnt.at(a.at(i))*(cnt.at(a.at(i)) - 1)/2;
        ans += (cnt.at(a.at(i)) - 1)*(cnt.at(a.at(i)) - 2)/2;
        cout << ans << endl;
    }
    return 0;
}