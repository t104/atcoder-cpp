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
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<P> ans;
    auto add = [&](int x, int y) {
        ans.emplace_back(x, y);
        a[y] += a[x];
    };

    int mi = INF, mx = -INF;
    rep(i,n) {
        chmin(mi, a[i]);
        chmax(mx, a[i]);
    }

    if (0 < mi) {
        rep(i,n-1) {
            add(i, i+1);
        }
    } else if (mx < 0) {
        for (int i = n-1; 0 < i; --i) {
            add(i, i-1);
        }
    } else if (abs(mi) <= abs(mx)) {
        int mxi = max_element(a.begin(), a.end()) - a.begin();
        rep(i,n) add(mxi, i);
        rep(i,n-1) {
            add(i, i+1);
        }
    } else {
        int mii = min_element(a.begin(), a.end()) - a.begin();
        rep(i,n) add(mii, i);
        for (int i = n-1; 0 < i; --i) {
            add(i, i-1);
        }
    }

    cout << ans.size() << endl;
    for (auto [x,y]: ans) {
        cout << x+1 << ' ' << y+1 << endl;
    }
    // rep(i,n) cout << a[i] << ' ';
    // cout << endl;
    return 0;
}