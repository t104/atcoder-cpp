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
    int h, w, n;
    cin >> h >> w >> n;
    vector<P> a(n), b(n), ans(n);
    rep(i,n) {
        int ai, bi;
        cin >> ai >> bi;
        a[i] = make_pair(ai, i);
        b[i] = make_pair(bi, i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    h = 0, w = 0;
    rep(i,n) {
        if (0 < i) {
            if (a[i-1].first != a[i].first) h++;
            if (b[i-1].first != b[i].first) w++;
        }
        ans[a[i].second].first = h;
        ans[b[i].second].second = w;
    }
    rep(i,n) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }

    return 0;
}

