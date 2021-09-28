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

using mint = modint998244353;

int main() {
    int n, d;
    cin >> n >> d;
    mint ans;
    vector<mint> two(n+5, 1);
    rep(i,n) two[i+1] = two[i] * 2;
    rep(i, d+1) {
        int a = i, b = d - i;
        if (n <= max(a, b)) continue;
        mint k = two[n - max(a, b)] - mint(1);
        mint now = k * two[max(a-1, 0)] * two[max(b-1, 0)];
        ans += now;
    }
    ans *= 2;
    cout << ans.val() << endl;
    return 0;
}

