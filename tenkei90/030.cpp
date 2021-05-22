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

vector<int> primes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = 2; i*j <= n; ++j)
                isPrime[i*j] = false;
        }
    }
    vector<int> res;
    rep(i, n+1) {
        if (isPrime[i]) res.push_back(i);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    auto p = primes(n);
    vector<int> cnt(n+1);
    for (auto pi: p) {
        for (int i = 1; pi*i <= n+1; ++i) {
            cnt[pi*i]++;
        }
    }
    int ans = 0;
    rep(i,n+1) {
        if (k <= cnt[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}