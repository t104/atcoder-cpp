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
    ll K;
    cin >> n >> K;
    vector<int> a(n);
    for (auto &ai : a) {
        cin >> ai;
        ai--;
    }
    int k = 1;
    while ((1LL<<k) < K) k++;
    vector<vector<int>> doubling(k, vector<int>(n));
    rep(i,n) {
        doubling[0][i] = a[i];
    }
    for (int ki = 0; ki+1 < k; ++ki) {
        rep(i,n) {
            doubling[ki+1][i] = doubling[ki][doubling[ki][i]];
        }
    }
    int ans = 0;
    rep(i,k) {
        if ((K>>i)&1) ans = doubling[i][ans];
    }
    cout << ans+1 << endl;
    return 0;
}