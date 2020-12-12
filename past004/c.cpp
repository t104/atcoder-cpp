#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
int dw[] = {0, 1, 1, 0, -1, -1, 0};
int dh[] = {0, 0, 1, 1, -1, 0, -1};

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> ans(n,vector<int>(m));
    rep(i,n) cin >> s.at(i);
    rep(i,n) {
        rep(j,m) {
            for (int dh = -1; dh <= 1; ++dh) {
                for (int dw = -1; dw <= 1; ++dw) {
                    int h = i + dh;
                    int w = j + dw;
                    if (0 <= h && h < n && 0 <= w && w < m && s[h][w] == '#')
                        ++ans[i][j];
                }
            }
        }
    }

    rep(i,n) {
        rep(j,m) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}