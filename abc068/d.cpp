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

void test(int k) {
    int n = 5;
    vector<int> a(n,n-1);
    rep(i,k) {
        auto mi = min_element(a.begin(), a.end());
        *mi += n+1;
        rep(j,n) a[j]--;
        rep(j,n) cout << a[j] << ' ';
        cout << endl;
    }
}

int main() {
    const int n = 50;
    ll k;
    cin >> k;
    vector<ll> ans(n, n-1+k/n);
    rep(i,k%n) {
        auto mi = min_element(ans.begin(), ans.end());
        *mi += n+1;
        rep(j,n) ans[j]--;
    }
    
    cout << n << endl;
    rep(i,n) {
        cout << ans[i];
        if (i < n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}