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
    vector<int> l(n), r(n);
    rep(i,n) {
        int t;
        cin >> t >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        if (t == 2 || t == 4) {
            r[i]--;
        }
        if (t == 3 || t == 4) {
            l[i]++;
        }
    }
    int ans = 0;
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            if (l[i] <= r[j] && l[j] <= r[i]) {
                // cout << i << ' ' << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}