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


const int MX = 10000;
vector<int> dp(MX, INF);

void add(int x, vector<int> &a) {
    x *= 10;
    if (MX <= x) return;
    for (int i : {1,2,3}) {
        int nx = x + i;
        a.push_back(nx);
        add(nx, a);
    }
}

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
    vector<int> a;
    add(0, a);
    dp[0] = 0;
    for (auto &ai: a) {
        chmin(dp[ai], 1);
    }
    for (int i = 2; i < MX; ++i) {
        for (int j = 1; j < i; ++j) {
            int k = i - j;
            chmin(dp[i], dp[j] + dp[k]);
        }
    }
    // rep(i, MX) {
    //     if (dp[i] == 5) cout << i << endl;
    // }
    for (int i = 1; i < MX; ++i) {
        string s = to_string(i);
        cout << dp[i] << ' ' << solve(s) << endl;
        assert(dp[i] == solve(s));
    }
    return 0;
}