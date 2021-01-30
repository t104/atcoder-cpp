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
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> r(n), b(n);
    rep(i,n) cin >> r[i].first >> r[i].second;
    rep(i,n) cin >> b[i].first >> b[i].second;
    sort(b.begin(), b.end());
    sort(r.begin(), r.end(), [&](P x, P y) {
        return y.second < x.second;
    });
    vector<bool> choose(n, false);
    int ans = 0;
    rep(i,n) {
        rep(j,n) {
            if (!choose[j]) {
                if (r[j].first < b[i].first && r[j].second < b[i].second) {
                    choose[j] = true;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}