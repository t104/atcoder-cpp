#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;

const int mod = 1000000007;
const int max_n = 55;
int n;
ll k;
vvl A;

vvl multiply(vvl &a, vvl &b) {
    vvl res(n, vl(n,0));
    rep(i,n) rep(j,n) rep(k,n) {
        // res : # routes from i to j (length = k + 1)
        // a   : # routes from i to k
        // b   : # routes from k to j
        // i ==> k ==> j
        (res[i][j] += a[i][k] * b[k][j]) %= mod;
    }
    return res;
}

vvl pow(vvl m, ll k) {
    vvl res(n, vl(n, 0));
    rep(i,n) res[i][i] = 1;

    while (0 < k) {
        if (k&1) res = multiply(res, m);
        m = multiply(m,m);
        k >>= 1;
    }

    return res;
}

int main() {
    cin >> n >> k;
    A.assign(n, vl(n));
    rep(i,n) rep(j,n) {
        cin >> A[i][j];
    }

    A = pow(A, k);

    ll ans = 0;
    rep(i,n) rep(j,n) {
        ans += A[i][j];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}