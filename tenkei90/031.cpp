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

int grundy[55][1555];

void init() {
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= 1500; ++j) {
        vector<int> mex(1555);
        if (1 <= i) {
            mex[grundy[i-1][j+i]] = 1;
        }
        if (2 <= j) {
            for (int k = 1; k <= j/2; ++k)
                mex[grundy[i][j-k]] = 1;
        }
        for (int k = 0; k < 1555; ++k) {
            if (mex[k] == 0) {
                grundy[i][j] = k;
                break;
            }
        }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n+1), b(n+1);
    rep(i,n) cin >> w[i+1];
    rep(i,n) cin >> b[i+1];

    init();
    int sum_xor = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n) i += 0;
        sum_xor ^= grundy[w[i]][b[i]];
    }
    if (sum_xor) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}