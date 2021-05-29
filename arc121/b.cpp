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

ll calc(vector<ll> &x, vector<ll> &y) {
    ll res = LINF;
    int xn = x.size();
    rep(i,xn) {
        int p = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
        if (p < y.size()) {
            chmin(res, abs(x[i] - y[p]));
        }
        if (0 < p) {
            chmin(res, abs(x[i] - y[p-1]));
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> r, g, b;
    rep(i,2*n) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') {
            r.push_back(a);
        }
        else if (c == 'G') {
            g.push_back(a);
        }
        else {
            b.push_back(a);
        }
    }

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    int rn = r.size();
    int gn = g.size();
    int bn = b.size();

    ll ans = LINF;
    if (rn%2 == 1 && gn%2 == 1) {
        chmin(ans, calc(r,g));
        chmin(ans, calc(b,r) + calc(b,g));
    }
    else if (gn%2 == 1 && bn%2 == 1) {
        chmin(ans, calc(g,b));
        chmin(ans, calc(r,g) + calc(r,b));
    }
    else if (bn%2 == 1 && rn%2 == 1) {
        chmin(ans, calc(b,r));
        chmin(ans, calc(g,b) + calc(g,r));
    }
    else {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}