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
    vector<ll> ans(n+1);
    map<ll, int> mp;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[a + b]--;
    }
    ll sum = 0, prev = 0;
    for (auto &p: mp) {
        ans[sum] += p.first - prev;
        sum += p.second;
        prev = p.first;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}

