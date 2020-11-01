#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    mint sa = a * (a+1) / 2;
    mint sb = b * (b+1) / 2;
    mint sc = c * (c+1) / 2;
    mint ans = sa * sb * sc;
    cout << ans.val() << endl;
    return 0;
}