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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    map<char, vector<int>> smap;
    rep(i,n) smap[s[i]].push_back(i);
    ll ans = 0, now = -1;
    rep(i,m) {
        if (smap.count(t[i]) == 0) {
            cout << -1 << endl;
            return 0;
        }
        vector<int> &pos = smap[t[i]];
        auto itr = lower_bound(pos.begin(), pos.end(), now+1);
        if (itr == pos.end()) {
            ans += n - now;
            ans += pos[0];
            now = pos[0];
        }
        else {
            ans += *itr - now;
            now = *itr;
        }
    }
    cout << ans << endl;
    return 0;
}