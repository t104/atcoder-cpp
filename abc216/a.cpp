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
    auto p = s.find('.');
    int x = stoi(s.substr(0, p));
    int y = stoi(s.substr(p + 1, s.size() - p - 1));
    if (y <= 2) {
        cout << x << '-' << endl;
    } else if (3 <= y && y <= 6) {
        cout << x << endl;
    } else {
        cout << x << '+' << endl;
    }

    return 0;
}