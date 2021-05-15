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
vector<int> req;
bool ok (string x) {
    for (auto i: req) {
        bool ok1 = false;
        for (char d: x) {
            if ('0'+i == d) ok1 = true;
        }
        if (!ok1) return false;
    }
    for (auto c: x) {
        if (s[c-'0'] == 'x') return false;
    }
    return true;
}

int main() {
    cin >> s;
    rep(i,10) {
        if (s[i] == 'o') req.push_back(i);
    }
    int ans = 0;
    for (char c = '0'; c <= '9'; ++c) {
        for (char d = '0'; d <= '9'; ++d) {
            for (char e = '0'; e <= '9'; ++e) {
                for (char f = '0'; f <= '9'; ++f) {
                    if (ok({c,d,e,f})) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}