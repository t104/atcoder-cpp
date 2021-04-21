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

using mint = modint1000000007;

struct fact {
    int mx;
    vector<mint> f;
    fact(int mx): mx(mx) {
        f.resize(mx+1);
        f[0] = 1;
        rep(i,mx) {
            f[i+1] = (i+1) * f[i];
        }
    }

    mint get(int n) {
        return f[n];
    }
};



int main() {
    int n, k;
    cin >> n >> k;
    fact f(n);
    mint ans = 0;
    for (int ki = 0; ki <= min(k, n-1); ++ki) {
        ans += f.get(n) * f.get(n-ki).inv() * f.get(ki).inv()
        * f.get(n-1) * f.get(n-1-ki).inv() * f.get(ki).inv();
    }
    cout << ans.val() << endl;
    return 0;
}