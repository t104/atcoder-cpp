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
    int n, r;
    string s;
    cin >> n >> r >> s;
    int ans = 0, p = 0;
    int i = n-1;
    for (; 0 <= i; --i) {
        if (s[i] == '.') {
            ans = max(0, i-r+1);
            break;
        }
    }
    for (; 0 <= i; --i) {
        if (p) p--;
        if (s[i] == '.' && p == 0) {
            ans++;
            p = r;
        }
    }
    cout << ans << endl;

    return 0;
}