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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    map<int, int> mp;
    int ans = 0, now = 0;
    rep(i,n) mp[c[i]] = 0;
    rep(i,n) {
        if (mp.at(c[i]) == 0) {
            now++;
        }
        mp.at(c[i])++;
        if (0 <= i-k) {
            mp.at(c[i-k])--;
            if (mp.at(c[i-k]) == 0) now--;
        }
        chmax(ans, now);
    }
    cout << ans << endl;
    return 0;
}