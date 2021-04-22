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
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    dsu uf(n);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        uf.merge(x,y);
    }
    

    int ans = 0;
    for (auto g: uf.groups()) {
        set<int> st;
        for (auto i: g) {
            st.insert(p[i]);
        }
        for (auto i: g) {
            if (st.count(i)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}