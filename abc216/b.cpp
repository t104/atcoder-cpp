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
using P = pair<string,string>;

int main() {
    set<P> names;
    int n;
    cin >> n;
    bool ok = false;
    rep(i,n) {
        string s, t;
        cin >> s >> t;
        P name = make_pair(s, t);
        if (names.count(name)) ok = true;
        names.insert(name);
    }
    cout << (ok ? "Yes": "No") << endl;
    return 0;
}