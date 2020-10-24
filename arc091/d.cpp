#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int b = k+1; b <= n; ++b) {
        ll x = 0;
        x += (ll) n/b * (b-k);
        if (k == 0) x += max(0, n%b - k);
        else x += max(0LL, (ll) n%b - k + 1);
        ans += x;
    }
    cout << ans << endl;
    return 0;
}