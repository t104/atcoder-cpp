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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    x--, y--;
    int ans = 0;
    for (int i = x; i < h; ++i) {
        if (s[i][y] == '#') break;
        ans++;
    }
    for (int i = x-1; 0 <= i; --i) {
        if (s[i][y] == '#') break;
        ans++;
    }
    for (int i = y; i < w; ++i) {
        if (s[x][i] == '#') break;
        ans++;
    }
    for (int i = y-1; 0 <= i; --i) {
        if (s[x][i] == '#') break;
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}