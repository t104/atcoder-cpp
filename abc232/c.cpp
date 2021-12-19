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
    vector<vector<int>> aoki(n, vector<int>(n)), taka(n, vector<int>(n));
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        aoki[u][v] = 1;
        aoki[v][u] = 1;
    }
    rep(i,m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        taka[u][v] = 1;
        taka[v][u] = 1;
    }
    vector<int> order(n);
    rep(i,n) order[i] = i;
    do {
        bool ok = true;
        rep(i,n) rep(j,n) {
            int u = order[i];
            int v = order[j];
            if (aoki[u][v] != taka[i][j]) {
                ok = false;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(order.begin(), order.end()));
    cout << "No" << endl;
    return 0;
}

