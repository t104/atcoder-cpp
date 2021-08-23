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
    int n, w;
    cin >> n >> w;
    mf_graph<int> mf(n+2);
    int sum = 0;
    rep(i,n) {
        int a;
        cin >> a;
        mf.add_edge(0, i+1, a);
        sum += a;
    }
    for (int i = 1; i <= n; ++i) {
        mf.add_edge(i, n+1, w);
    }
    rep(i,n) {
        int k;
        cin >> k;
        rep(j,k) {
            int c;
            cin >> c;
            mf.add_edge(c, i+1, INF);
        }
    }
    cout << sum - mf.flow(0, n+1) << endl;
    return 0;
}