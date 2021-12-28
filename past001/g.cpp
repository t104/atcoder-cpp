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

const int MX = 60000;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, -INF));
    rep(i,n-1) {
        for (int j = i+1; j < n; ++j) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    int ans = -INF;
    rep(i, MX) {
        int flg = i;
        int sum = 0;
        vector<vector<int>> g(3);
        rep(j,n) {
            int gi = flg % 3;
            g[gi].push_back(j);
            flg /= 3;
        }
        for (auto &gi : g) {
            int sz = gi.size();
            rep(j,sz) {
                for (int k = j + 1; k < sz; ++k) {
                    sum += a[gi[j]][gi[k]];
                }
            }
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

