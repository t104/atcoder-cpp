#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), p(n);
    rep(i,n) cin >> p.at(i);
    rep(i,n) cin >> c.at(i);
    rep(i,n) p.at(i)--;
    ll ans = -1e18;
    rep(start,n) {
        int pos = start;
        vector<int> vt;
        ll total = 0;
        while (true) {
            pos = p.at(pos);
            vt.push_back(c.at(pos));
            total += c.at(pos);
            if (pos == start) break;
        }
        int cycle = vt.size();
        ll now = 0;
        rep(i,cycle) {
            now += vt.at(i);
            ll s = now;
            // 1周しない分が i+1 step
            if (k < i+1) break;
            if (total > 0) {
                ll e = (k-i-1)/cycle;
                s += total * e;
            }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}