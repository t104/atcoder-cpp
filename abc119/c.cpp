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

vector<int> a(3);

int ans = INF;

int calc(vector<int> &l) {
    int n = l.size();
    int res = INF;
    rep(i,n) rep(j,n) rep(k,n) {
        if (i == j) continue;
        if (j == k) continue;
        if (k == i) continue;
        int m = 0;
        chmin(res, abs(l[i]-a[0]) + abs(l[j]-a[1]) + abs(l[k]-a[2]));
    }
    return res;
}

void dfs(vector<int> l, int p) {
    chmin(ans, p + calc(l));
    int n = l.size();
    if (n == 3) return;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            vector<int> nl;
            nl.push_back(l[i]+l[j]);
            rep(k,n) {
                if (k == i || k == j) continue;
                nl.push_back(l[k]);
            }
            dfs(nl, p + 10);
        }
    }
}

int main() {
    int n;
    cin >> n;
    rep(i,3) cin >> a[i];
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    dfs(l, 0);
    cout << ans << endl;

    return 0;
}