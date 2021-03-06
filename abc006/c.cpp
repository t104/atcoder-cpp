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
    int n, m;
    cin >> n >> m;
    int k = m - 2*n;
    for (int z = 0; z <= k; z++) {
        int y = k - 2*z;
        int x = n - y - z;
        if (0 <= x && 0 <= y) {
            printf("%d %d %d\n", x, y, z);
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}