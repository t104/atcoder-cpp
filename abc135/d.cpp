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

using mint = modint1000000007;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    const int mod = 13;
    vector<mint> now(mod), next(mod);
    reverse(s.begin(), s.end());
    int d = 1;
    if (s[0] == '?') {
        rep(i,10) now[i] = 1;
    }
    else {
        now[s[0] - '0'] = 1;
    }
    for (int i = 1; i < n; ++i) {
        d = d*10%mod;
        if (s[i] == '?') {
            rep(j,10) {
                rep(k,mod) {
                    next[(j*d+k)%mod] += now[k];
                }
            }
        }
        else {
            int j = s[i] - '0';
            rep(k,mod) {
                next[(j*d+k)%mod] += now[k];
            }
        }
        rep(k,mod) {
            now[k] = next[k];
            next[k] = 0;
        }
    }

    cout << now[5].val() << endl;

    return 0;
}