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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = INF;
    vector<int> x(15000005);
    rep(i,m) x[a[i]]++;
    rep(i,m+1) {
        if (x[i] == 0) {
            chmin(ans, i);
            break;
        }
    }

    rep(i,n-m) {
        x[a[i]]--;
        x[a[i+m]]++;
        if (a[i] < ans && x[a[i]] == 0) {
            ans = a[i];
        }
    }

    cout << ans << endl;
    return 0;
}
