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

int solve(string s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    int ans = 1;
    while (ans < 5) {
        int up = 0;
        bool ok = true;
        int k = ans;
        rep(i,n) {
            int d = s[i] - '0';
            d -= up;
            up = 0;
            while (0 <= k) {
                if (k <= d && d <= 3*k) {
                    break;
                } else if (i < n-1 && k <= d + 10 && d + 10 <= 3 * k) {
                    up = 1;
                    break;
                }
                k--;
            }
            if (k == -1) {
                ok = false;
                break;
            }
        }
        if (ok) return ans;
        ans++;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}

