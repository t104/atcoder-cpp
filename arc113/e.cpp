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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int bn = 0, an = 0;
    int posa = -1, posb = -1;
    rep(i,n) {
        if (s[i] == 'b') {
            bn++;
            posb = i;
            continue;
        }
        an++;
        posa = i;
    }

    stringstream ss;
    if (posb < posa) {
        rep(i,bn) ss << 'b';
        for (int i = posb+1; i <= posa; ++i) {
            ss << 'a';
        }
    }

    cout << ss.str() << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i,t) solve();
    return 0;
}