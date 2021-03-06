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
    string s;
    cin >> n >> s;
    vector<string> patterns;
    string t = "ABXY";
    rep(i,4) rep(j,4) {
        patterns.push_back({t[i], t[j]});
    }

    int m = patterns.size();
    int ans = INF;
    rep(i,m) rep(j,m) {
        string x = patterns[i];
        string y = patterns[j];
        int cnt = 0;
        rep(k,n) {
            cnt++;
            if (n-1 <= k) continue;
            string sub = s.substr(k,2);
            if (sub == x || sub == y) ++k;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}