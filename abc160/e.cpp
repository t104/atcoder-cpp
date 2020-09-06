#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);
    rep(i,a) cin >> p.at(i);
    rep(i,b) cin >> q.at(i);
    rep(i,c) cin >> r.at(i);
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    vector<int> sub(x+y+c);
    rep(i,x) sub.at(i) = p.at(i);
    rep(i,y) sub.at(x+i) = q.at(i);
    rep(i,c) sub.at(x+y+i) = r.at(i);
    sort(sub.begin(), sub.end());
    reverse(sub.begin(), sub.end());
    ll ans = 0;
    rep(i,x+y) ans += sub.at(i);
    cout << ans << endl;
    return 0;
}