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

const int MX = 1e9;

int main() {
    int L, Q;
    cin >> L >> Q;
    vector<int> c(Q), x(Q);
    rep(i,Q) cin >> c[i] >> x[i];
    vector<int> edges = {0};
    rep(i,Q) {
        if (c[i] == 1) edges.push_back(x[i]);
    }
    sort(edges.begin(), edges.end());
    int n = edges.size();
    vector<int> len(n);
    rep(i,n-1) {
        len[i] = edges[i+1] - edges[i];
    }
    len[n-1] = L - edges[n-1];
    vector<int> ans;
    dsu uf(n);
    for (int i = Q-1; 0 <= i; --i) {
        int p = lower_bound(edges.begin(), edges.end(), x[i]) - edges.begin();
        if (c[i] == 1) {
            int l = len[uf.leader(p-1)] + len[uf.leader(p)];
            uf.merge(p, p-1);
            len[uf.leader(p)] = l;
        } else {
            ans.push_back(len[uf.leader(p-1)]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto &a: ans) cout << a << endl;

    return 0;
}