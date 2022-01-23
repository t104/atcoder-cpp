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

int a;
const int MX = 1000010;
int dp[MX];

void dfs(int n) {
    if (n == 1) {
        return;
    }
    if (n % a == 0) {
        if (chmin(dp[n/a], dp[n] + 1)) {
            dfs(n/a);
        }
    }
    if (10 < n && n % 10 != 0) {
        string s = to_string(n);
        string t = s.substr(1, s.size() - 1) + s.substr(0, 1);
        if (chmin(dp[stoi(t)], dp[n] + 1)) {
            dfs(stoi(t));
        }
    }
}

int main() {
    int n;
    cin >> a >> n;
    rep(i, MX) dp[i] = INF;
    dp[n] = 0;
    queue<int> que;
    que.push(n);
    while (que.size()) {
        int now = que.front(); que.pop();
        if (now % a == 0) {
            if (chmin(dp[now/a], dp[now] + 1)) {
                que.push(now/a);
            }
        }
        string s = to_string(now);
        if (10 < now && s[1] != '0' && now % 10 != 0) {
        string t = s.substr(1, s.size() - 1) + s.substr(0, 1);
            if (chmin(dp[stoi(t)], dp[now] + 1)) {
                que.push(stoi(t));
            }
        }
    }
    if (dp[1] < INF) {
        cout << dp[1] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

