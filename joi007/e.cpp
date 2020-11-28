#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> cookie(r, vector<int>(c));
    rep(i,r) rep(j,c) cin >> cookie[i][j];

    int ans = 0;
    rep(i, (1<<r)) {
        int sum = 0;
        rep(j,c) {
            int sub = 0;
            rep(k,r) {
                if ((i>>k)&1) {
                    sub += !cookie[k][j];
                }
                else sub += cookie[k][j];
            }
            sum += max(sub, r - sub);
        }
        chmax(ans, sum);
    }

    cout << ans << endl;
    return 0;
}