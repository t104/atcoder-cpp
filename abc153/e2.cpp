#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main()
{
    int h, n;
    cin >> h >> n;

    int dp[n+1][h+1];
    rep(i, n+1)
    {
        rep(j, h)
        {
            dp[i][j+1] = INF;
        }
        dp[i][0] = 0;
    }

    rep(i, n)
    {
        int attack, cost;
        cin >> attack >> cost;
        rep(j, h)
        {
            if(h < j+attack) {
                int m1 = min(dp[i+1][h], dp[i+1][h-attack]+cost);
                dp[i+1][h] = min(m1, dp[i+1][j]+cost);
            }
            else dp[i+1][j+attack] = min(dp[i][j+attack], dp[i+1][j]+cost);
        }
    }
    // rep(i,n+1) {
    //     rep(j,h+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][h] << endl;
    return 0;
}