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
    vector<vector<int>> status(n, vector<int>(5));
    rep(i,n) rep(j,5) cin >> status[i][j];

    int l = 0, r = INF;
    while (l+1 < r) {
        int m = (l+r)/2;
        bool ok = false;
        vector<int> flag;
        rep(i,n) {
            int x = 0;
            rep(j,5) {
                if (m <= status[i][j]) {
                    x |= 1<<j;
                }
            }
            flag.push_back(x);
        }
        sort(flag.begin(), flag.end());
        flag.erase(unique(flag.begin(), flag.end()), flag.end());
        int mask = (1<<5) - 1;
        for (auto i: flag) {
            for (auto j: flag) {
                for (auto k: flag) {
                    if ((i|j|k) == mask) ok = true;
                }
            }
        }
        if (ok) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}