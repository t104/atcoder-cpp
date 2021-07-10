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

using mint = modint1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> x(q, vector<int>(3));
    vector<ll> w(q);
    rep(i,q) {
        for (auto &xi: x[i]) {
            cin >> xi;
            xi--;
        }
        cin >> w[i];
    }

    mint ans = 1;
    rep(i,60) {
        int cnt = 0;
        rep(s, 1<<n) {
            int ok = 1;
            rep(j,q) {
                int flg = 0;
                for (auto &xi: x[j]) flg |= (s>>xi)&1;
                if (flg != ((w[j]>>i)&1)) {
                    ok = 0;
                }
            }
            cnt += ok;
        }
        ans *= cnt;
    }
    cout << ans.val() << endl;
    return 0;
}