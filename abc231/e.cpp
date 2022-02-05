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

int n;
ll x;
vector<ll> a;
ll ans;
map<ll, ll> mp;

void dfs(int i, ll cnt, ll r) {
    if (mp.count(r) && mp.at(r) < cnt) {
        return;
    }
    else mp[r] = cnt;
    if (r == 0) {
        chmin(ans, cnt);
        return;
    }
    ll q = r / a[i];
    if (0 < i && a[i] * (q + 1) - r < r % a[i])
        dfs(i-1, cnt + q + 1, a[i] * (q + 1) - r);
    dfs(i-1, cnt + q, r % a[i]);
}

int main() {
    cin >> n >> x;
    a.resize(n);
    rep(i,n) cin >> a[i];
    ans = LINF;
    dfs(n-1, 0LL, x);
    cout << ans << endl;
    return 0;
}

