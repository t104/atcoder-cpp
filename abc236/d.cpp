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
    cin >> n;
    int n2 = 2*n;
    vector<vector<ll>> a(n2, vector<ll>(n2));
    rep(i,n2) {
        for (int j = i+1; j < n2; ++j) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    return 0;
}