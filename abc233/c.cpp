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
using P = pair<ll,ll>;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<int> c(n);
    vector<vector<ll>> a(n);
    rep(i,n) {
        cin >> c[i];
        a[i].resize(c[i]);
        rep(j, c[i]) {
            cin >> a[i][j];
        }
    }
    queue<ll> que;
    que.push(x);
    rep(i,n) {
        queue<ll> tmp;
        while (que.size()) {
            ll ai = que.front(); que.pop();
            for (auto &aj : a[i]) {
                if (ai % aj == 0) {
                    tmp.push(ai / aj);
                }
            }
        }
        swap(que, tmp);
    }
    int ans = 0;
    while (que.size()) {
        ll ai = que.front(); que.pop();
        if (ai == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}

