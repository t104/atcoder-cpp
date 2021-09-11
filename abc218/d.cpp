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
    set<vector<int>> cnt;
    rep(i,n) st.insert(make_pair(x[i], y[i]));
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            if (x[i] == x[j]) continue;
            if (y[i] == y[j]) continue;
            // cout << min(x[i], x[j]) << ' ' <<  min(y[i], y[j]) << ' ' <<  max(x[i], x[j]) << ' ' <<  max(y[i], y[j]) << endl;
            if (st.count(make_pair(x[i], y[j])) && st.count({x[j], y[i]})) {
                cnt.insert({min(x[i], x[j]), min(y[i], y[j]), max(x[i], x[j]), max(y[i], y[j])});
            }
        }
    }
    cout << cnt.size() << endl;
    return 0;
}

