#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> dp(h+1, INF);
    dp[0] = 0;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        rep(j,h) {
            int nj = min(j+a,h);
            dp[nj] = min(dp[nj], dp[j] + b);
        }
    }
    for(auto i : dp) cout << i << " ";
    cout << endl;
    cout << dp[h] << endl;
    return 0;
}