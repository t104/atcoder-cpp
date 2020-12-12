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

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    rep(i,h) cin >> grid.at(i);
    int ans = 0;
    rep(i,h) rep(j,w) {
        int d = 0;
        for (char c = '0'; c <= '9'; ++c) {
            for (int d = 0; i+d < h &&  j+d < w; ++d) {
                int count = 0;
                for (int di = i; di <= i+d; ++di) {
                    for (int dj = j; dj <= j+d; ++dj) {
                        if (grid.at(di).at(dj) != c) ++count;
                    }
                }
                if (count <= k) {
                    chmax(ans, d+1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}