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
using P = pair<ll,ll>;

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    rep(i,n) cin >> points[i].first >> points[i].second;
    sort(points.begin(), points.end());
    int ans = n;
    rep(i,n) {
        for (int j = 0; j < n; ++j) {
            ll p = points[j].first - points[i].first;
            ll q = points[j].second - points[i].second;
            if (p == 0 && q == 0) continue;
            int cnt = 0;
            vector<int> flg(n);
            rep(k,n) {
                for (int l = 0; l < n; ++l) {
                    if (flg[l]) continue;
                    if (points[l].first - points[k].first == p && points[l].second - points[k].second == q) {
                        ++cnt;
                        flg[l] = 1;
                        break;
                    }
                }
            }
            chmin(ans,n-cnt);
        }
    }

    cout << ans << endl;
    return 0;
}