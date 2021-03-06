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

int solve (string s) {
    reverse(s.begin(), s.end());
    int n = s.size();

    ll ans = 0;
    int up = 0;
    rep(i,n) {
        int d = s[i] - '0';
        if (up == 1) d++;
        if (d < 5) up = 0;
        else if (d == 5) {
            if (i+1 < n && 5 <= s[i+1]-'0') up = 1;
            else up = 0;
        }
        else up = 1;
        d %= 10;
        ans += min(d, 10-d);
        if (i == n-1) ans += up;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}