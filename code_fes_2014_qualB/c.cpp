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
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    int n = s[0].size();
    vector<vector<int>> cnt(3, vector<int>(26));
    rep(i,3) {
        rep(j,n) {
            cnt[i][s[i][j] - 'A']++;
        }
    }
    bool ok = true;
    int m1 = 0, m2 = 0;
    rep(i,26) {
        if (cnt[0][i] + cnt[1][i] < cnt[2][i]) ok = false;
        m1 += max(0, cnt[2][i] - cnt[0][i]);
        m2 += max(0, cnt[2][i] - cnt[1][i]);
    }
    if (n/2 < m1 || n/2 < m2) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}