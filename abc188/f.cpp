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

map<ll, ll> mp;
ll x, y;

ll dfs(ll yi) {
    if (mp.count(yi)) {
        return mp.at(yi);
    }
    if (yi == 1) {
        return mp[yi] = abs(x-yi);
    }
    if (yi%2 == 1) {
        return mp[yi] = min({abs(x-yi), dfs((yi+1)/2) + 2, dfs((yi-1)/2) + 2});
    }
    return mp[yi] = min(abs(x-yi), dfs(yi/2) + 1);
}

int main() {
    cin >> x >> y;
    cout << dfs(y) << endl;
    return 0;
}