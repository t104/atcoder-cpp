#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,ll>; // to, distance

vector<vector<P>> g;

void dfs(int now, int from, ll d, vector<ll>& distance) {
    for (auto p : g.at(now)) {
        if (p.first == from) continue;
        distance.at(p.first) = d + p.second;
        dfs(p.first, now, d + p.second, distance);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    vector<ll> c(n-1);
    rep(i,n-1) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        a.at(i)--; b.at(i)--;
    }
    int q, k;
    cin >> q >> k;
    k--;
    vector<int> x(q), y(q);
    rep(i,q) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--; y.at(i)--;
    }

    g.resize(n);
    rep(i,n-1) {
        g.at(a.at(i)).push_back({b.at(i), c.at(i)});
        g.at(b.at(i)).push_back({a.at(i), c.at(i)});
    }

    vector<ll> d(n, -1LL);
    d.at(k) = 0;
    dfs(k, -1, 0, d);

    rep(i,q) {
        cout << d.at(x.at(i)) + d.at(y.at(i)) << endl;
    }
    return 0;
}