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

void ng() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    int n;
    string s,t;
    cin >> n >> s >> t;
    vector<int> a, b;
    rep(i,n) {
        if (s[i] == '0') a.push_back(i);
        if (t[i] == '0') b.push_back(i);
    }
    if (a.size() != b.size()) ng();
    
    int ans = 0;
    int sz = a.size();
    rep(i,sz) {
        if (a[i] != b[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}