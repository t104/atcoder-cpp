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
    int ans = 0;
    rep(l,n-1) {
        vector<int> ai(n);
        for (int x = l; x < n-1; ++x) {
            int d = a[x] - ai[x];
            ai[x] += d;
            ai[x+1] += d;
            rep(i,n) cout << ai[i] << ' ';
            cout << endl;
            if (ai[x+1] == a[x+1]) {
                // cout << l << ' ' << x+1 << endl;
                ans++;
            }
        }
    }

    vector<int> ai(n);
    for (int x = 0; x < n-1; ++x) {
        int d = a[x] - ai[x];
        ai[x] += d;
        ai[x+1] += d;
    }
    cout << ans << endl;
    return 0;
}