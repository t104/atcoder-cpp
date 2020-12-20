#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 100010;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> x(m), y(m);
    rep(i,m) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--, y.at(i)--;
    }
    vector<int> minh(h, w), minw(w, h);
    rep(i,m) {
        chmin(minh.at(x.at(i)), y.at(i));
        chmin(minw.at(y.at(i)), x.at(i));
    }

    ll ans = 0;
    rep(i, minw.at(0)) {
        ans += minh.at(i);
    }
    rep(i, minh.at(0)) {
        ans += minw.at(i);
    }
    fenwick_tree<int> t(w);
    rep(y,minh.at(0)) t.add(y,1);
    vector<vector<int>> ends(h+1);
    rep(y,minh.at(0)) ends.at(minw.at(y)).push_back(y);
    rep(x, minw.at(0)) {
        for (int y : ends.at(x)) t.add(y, -1);
        ans -= t.sum(0, minh.at(x));
    }
    cout << ans << endl;
    return 0;
}