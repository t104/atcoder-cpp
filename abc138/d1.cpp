#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

vector<vector<int>> G;
vector<ll> ans;
vector<bool> visited;

void dfs(int v) {
    visited.at(v) = true;
    for (auto nv : G.at(v)) {
        if (visited.at(nv)) continue;
        ans.at(nv) += ans.at(v);
        dfs(nv);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    G.resize(n);
    ans.resize(n);
    visited.assign(n, false);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    rep(i,q) {
       int v, val;
       cin >> v >> val;
       --v;
       ans.at(v) += val;
    }

    dfs(0);    

    rep(i,n) {
        cout << ans.at(i);
        if (i < n-1) cout << ' ';
    }
    cout << endl;

    return 0;
}