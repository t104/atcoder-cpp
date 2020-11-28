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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> rel(n, vector<bool>(n, false));
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        rel[x][y] = true;
        rel[y][x] = true;
    }

    int ans = 1;
    for (int i = 1; i < (1<<n); ++i) {
        vector<int> group;
        for (int j = 0; j < n; ++j) {
            if ((i>>j)&1) group.push_back(j);
        }
        bool ok = true;
        for (int j = 0; j < group.size(); ++j) {
            for (int k = j+1; k < group.size(); ++k) {
                if (!rel[group[j]][group[k]]) ok = false;
            }
        }
        if (ok) chmax(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}