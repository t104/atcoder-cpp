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
    int l, r;
    string s;
    cin >> l >> r >> s;
    string ans;
    --l, --r;
    if (0 < l) {
        ans += s.substr(0, l);
    }
    string m = s.substr(l, r-l+1);
    reverse(m.begin(), m.end());
    ans += m;
    if (r < s.size()) {
        ans += s.substr(r+1, s.size() - r);
    }
    cout << ans << endl;
    return 0;
}

