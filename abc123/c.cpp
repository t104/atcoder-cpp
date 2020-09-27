#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const ll INF = (ll) 1e15 + 5;

int main() {
    ll n;
    cin >> n;
    vector<P> t(5);
    rep(i, 5) {
        cin >> t.at(i).first;
        t.at(i).second = i;
    }
    sort(t.begin(), t.end());
    ll m = t.at(0).first;
    int p = t.at(0).second;
    ll ans = n / m;
    if (n % m > 0) ans++;
    ans += 4;
    cout << ans << endl;
    return 0;
}