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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> comb(m, vector<int>(3));
    rep(i,m) rep(j,3) {
        cin >> comb.at(i).at(j);
        --comb.at(i).at(j);
    }
    int ans = 0;
    auto bomb = [&](int flg) {
        rep(i,m) {
            int c = 0;
            rep(j,3) {
                if ((flg>>comb.at(i).at(j)) & 1) ++c;
            }
            if (c == 3) return true;
        }
        return false;
    };
    
    for (int flg = 0; flg < (1<<n); ++flg) {
        if (bomb(flg)) continue;
        int count = 0;
        rep(i, n) {
            if ((flg>>i)&1) continue;
            int f = flg ^ (1<<i);
            if (bomb(f)) count++;
        }
        chmax(ans, count);
    }

    cout << ans << endl;
    return 0;
}