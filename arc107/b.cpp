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
    int N = 2*n;
    ll ans = 0;
    for (int i = 2; i <= N; ++i) {
        int A = k + i;
        int na = 0, ni = 0;
        if (A < 2 || N < A) continue;
        if (A <= n) {
            na = A-1;
        }
        else na = N-A+1;
        if (i <= n) ni = i-1;
        else ni = N-i+1;
        ans += (ll) na * ni;
    }
    cout << ans << endl;
    return 0;
}