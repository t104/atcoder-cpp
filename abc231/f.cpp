#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

void comp(vector<int> &a) {
    set<int>s(a.begin(), a.end());
    map<int,int> d;
    int cnt = 0;
    for (auto x:s) d[x] = cnt++;
    for (auto &x: a) x = d[x];
}

auto op=[](ll a, ll b){return a+b;};
auto e=[](){return 0LL;};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    comp(a), comp(b);

    vector<P> c(n);
    rep(i,n) c[i] = make_pair(-a[i], b[i]);
    sort(c.begin(), c.end());
    segtree<ll, op, e> seg(n);
    ll ans = 0;
    rep(i,n) {
        int cnt = 1;
        while (i+1 < n && c[i] == c[i+1]) cnt++, i++;
        int b = c[i].second;
        ans += cnt * (cnt + seg.prod(0, b+1));
        seg.set(b, seg.get(b) + cnt);
    }
    cout << ans << endl;
    return 0;
}

