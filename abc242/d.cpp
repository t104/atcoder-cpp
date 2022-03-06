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

string s;

int rec(ll h, ll w) {
    // cerr << h << ' ' << w << endl;
    if (h == 0) {
        return s[w] - 'A';
    }
    if (w == 0) {
        return (rec(0, w) + h) % 3;
    }
    if (w % 2 == 0) {
        return (rec(h-1, w/2) + 1) % 3;
    } else {
        return (rec(h, w-1) + 1) % 3;
    }
}

char solve() {
    ll t, k;
    cin >> t >> k;
    k--;
    int i = (rec(t, k) + 3) % 3;
    return 'A' + i;
}

int main() {
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        cout << solve() << endl;
    }
    return 0;
}