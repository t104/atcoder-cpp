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

string s;
ll m;
int n;
const ll MX = ((ll) 1e18) + 100000;

bool ok(ll x) {
    ll k = 0;
    for (auto c: s) {
        if (m/x < k) return false;
        k = k*x + (c-'0');
        if (m < k) return false;
    }
    return true;
}

int main() {
    cin >> s >> m;
    n = s.size();
    if (n == 1) {
        cout << (s[0] - '0' <= m) << endl;
        return 0;
    }
    ll x = -1;
    for (auto c: s) chmax(x, c-'0');
    ll l = x;
    ll r = LINF;
    while (l+1 < r) {
        ll mid = (l+r)/2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout << l-x << endl;
    return 0;
}