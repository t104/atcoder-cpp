#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    string s;
    string ans = "draw";
    cin >> s;
    int o = 0, x = 0;
    rep(i,5) {
        if (s.at(i) == 'o') {
            ++o;
            x = 0;
        }
        if (s.at(i) == 'x') {
            ++x;
            o = 0;
        }
        if (3 <= o) ans = "o";
        if (3 <= x) ans = "x";
    }
    cout << ans << endl;
    return 0;
}