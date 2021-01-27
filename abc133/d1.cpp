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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n);
    rep(i,n) {
        if (i%2 == 0) {
            ans[0] += a[i];
        }
        else {
            ans[0] -= a[i];
        }
    }
    for (int i = 1; i < n; ++i) {
        ans[i] = 2*a[i-1] - ans[i-1];
    }
    rep(i,n) {
        cout << ans[i] << endl;
    }
    return 0;
}