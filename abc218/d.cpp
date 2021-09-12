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
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    set<P> st;
    int ans = 0;
    rep(i,n) st.insert(make_pair(x[i], y[i]));
    rep(i,n) {
        rep(j,n) {
            if (x[i] < x[j] && y[i] < y[j] && st.count({x[i], y[j]}) && st.count({x[j], y[i]})) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

