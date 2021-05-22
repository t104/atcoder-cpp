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
    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];
    int m;
    cin >> m;
    vector<vector<int>> ng(n, vector<int>(n));
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        ng[x][y] = 1;
        ng[y][x] = 1;
    }
    vector<int> order(n);
    rep(i,n) order[i] = i;
    int ans = INF;
    do {
        bool ok = true;
        int sum = 0;
        rep(i,n) {
            if (0 < i && ng[order[i-1]][order[i]]) {
                ok = false;
            }
            sum += a[order[i]][i];
        }
        if (ok) chmin(ans, sum);
    } while (next_permutation(order.begin(), order.end()));
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}