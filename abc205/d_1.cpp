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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> cnt(n);
    rep(i,n) {
        cnt[i] = a[i] - (i+1);
    }
    rep(i,q) {
        ll k;
        cin >> k;
        int j = lower_bound(cnt.begin(), cnt.end(), k) - cnt.begin() - 1;
        if (0 <= j) {
            cout << k - cnt[j] + a[j] << endl;
        }
        else {
            cout << k << endl;
        }
    }
    return 0;
}