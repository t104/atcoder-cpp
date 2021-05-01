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

vector<ll> d, sum(41);
int n;
ll k;

ll dfs(int bit) {
    if (bit == 0) {
        if ((k>>bit)&1) return max(0LL, d[bit]);
        return 0LL;
    }

    if ((~k>>bit)&1) return dfs(bit-1);

    return max(sum[bit-1], max(0LL, d[bit]) + dfs(bit-1));
}

int main() {
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll tot = 0;
    rep(i,n) tot += a[i];
    if (k == 0) {
        cout << tot << endl;
        return 0;
    }
    d.resize(41,-tot);
    for (int i = 0; i <= 40; ++i) {
        rep(j,n) {
            d[i] += a[j]^(1LL<<i);
        }
    }
    rep(i,41) {
        sum[i] = max(0LL, d[i]);
    }
    rep(i,40) {
        sum[i+1] += sum[i];
    }

    cout << tot + dfs(40) << endl;

    return 0;
}