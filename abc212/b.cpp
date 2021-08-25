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
    string s;
    cin >> s;
    bool same = true;
    rep(i,3) {
        if (s[i] != s[i+1]) same = false;
    }
    bool step = true;
    rep(i,3) {
        int a = s[i] - '0';
        int b = s[i+1] - '0';
        if (b != (a+1)%10) step = false;
    }
    if (same || step) cout << "Weak" << endl;
    else cout << "Strong" << endl;
    return 0;
}