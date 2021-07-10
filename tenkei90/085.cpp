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
using P = pair<ll,int>;

vector<P> factors;
ll K;
int ans;

void dfs(ll x, ll y, int idx) {

    if (idx == factors.size()) {
        if (y < x) return;
        if (K/x/y < y) return;
        ans++;
        // printf("%lld %lld %lld\n", x, y, K/x/y);
        return;
    }

    for (int i = 0; i <= factors[idx].second; ++i) {
        for (int j = 0; i + j <= factors[idx].second; ++j) {
            ll p = 1, q = 1;
            rep(k,i) p *= factors[idx].first;
            rep(k,j) q *= factors[idx].first;
            dfs(x*p, y*q, idx+1);
        }
    }
}

int main() {
    cin >> K;
    ll k = K;
    for (ll i = 2; i*i <= k; ++i) {
        int cnt = 0;
        while (k % i == 0) {
            k /= i;
            cnt++;
        }
        factors.emplace_back(i, cnt);
    }
    if (1 < k) {
        factors.emplace_back(k, 1);
    }
    ans = 0;
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}