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

void dame() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ha = 0, ta = 0;;
    rep(i,n) {
        if (s[i] == 'a') ha++;
        else break;
    }
    rep(i,n) {
        if (s[n-1-i] == 'a') ta++;
        else break;
    }
    if (ta < ha) {
        dame();
    }
    string t = s.substr(0, n - (ta-ha));
    int m = t.size();
    rep(i,m) {
        if (t[i] != t[m-1-i]) {
            dame();
        }
    }
    cout << "Yes" << endl;
    return 0;
}

