#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const int times = 10;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(times));
    vector<vector<int>> p(n, vector<int>(times+1));
    rep(i,n) rep(j,times) cin >> f.at(i).at(j);
    rep(i,n) rep(j,times+1) cin >> p.at(i).at(j);
    int ans = -INF;
    for (int flg = 1; flg < (1<<10); ++flg) {
        int sum = 0;
        rep(i,n) {
            int count = 0;
            rep(j, times) {
                if ((flg>>j)&1 && f.at(i).at(j)) count++;
            }
            sum += p.at(i).at(count);
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}