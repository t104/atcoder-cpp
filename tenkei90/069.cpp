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

void print_ans(mint ans) {
    cout << ans.val() << endl;
    exit(0);
}

int main() {
    ll n, k;
    mint ans = 0;
    cin >> n >> k;
    if (n == 1LL) {
        ans = k;
        print_ans(ans);
    }
    if (n == 2LL) {
        if (k < 2) ans = 0;
        else ans = mint(k) * mint(k-1);
        print_ans(ans);
    }
    if (k < 3LL) {
        ans = 0;
        print_ans(ans);
    }
    ans = mint(k) * mint(k-1) * mint(k-2).pow(n-2);
    print_ans(ans);
    return 0;
}