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
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    dsu uf(n);
    rep(i,n) cin >> d[i];
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        d[u]--;
        d[v]--;
        uf.merge(u, v);
    }
    vector<vector<int>> temp(n);
    rep(i,n) {
        if (d[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        rep(_,d[i]) temp[uf.leader(i)].push_back(i);
    }

    vector<vector<int>> c2;
    vector<int> c1;
    rep(i,n) {
        if (temp[i].size() == 1) c1.push_back(temp[i][0]);
        else if (1 < temp[i].size()) c2.push_back(temp[i]);
    }

    vector<vector<P>> ans;
    for (auto v:c2) 
    
    return 0;
}