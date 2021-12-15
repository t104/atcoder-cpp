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

int main() {
    int n;
    cin >> n;
    vector<int> k(n);
    vector<ll> t(n);
    vector<vector<int>> a(n);
    rep(i,n) {
        cin >> t[i];
        cin >> k[i];
        a[i] = vector<int>(k[i]);
        rep(j,k[i]) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    vector<bool> learned(n, false);
    ll ans = 0;
    queue<int> que;
    que.push(n-1);
    while (que.size()) {
        int v = que.front(); que.pop();
        learned[v] = true;
        for (auto &nv : a[v]) {
            if (!learned[nv]) {
                que.push(nv);
            }
        }
    }
    rep(i,n) {
        if (learned[i]) {
            ans += t[i];
        }
    }
    cout << ans << endl;
    return 0;
}

