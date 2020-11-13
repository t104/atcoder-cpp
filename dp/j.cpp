#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 301;

int n;
double dp[max_n][max_n][max_n];

double f(int c1, int c2, int c3) {
    if (dp[c1][c2][c3] != -1) return dp[c1][c2][c3];
    double d = n;
    if (0 < c1) d += (double) c1 * f(c1-1, c2, c3);
    if (0 < c2) d += (double) c2 * f(c1+1, c2-1, c3);
    if (0 < c3) d += (double) c3 * f(c1, c2+1, c3-1);
    return dp[c1][c2][c3] = (double) d/(c1 + c2 + c3);
}

int main() {
    cout << std::fixed << std::setprecision(15);
    cin >> n;
    vector<int> a(4);
    rep(i,n) {
        int ai;
        cin >> ai;
        a.at(ai)++;
    }
    rep(i,max_n) rep(j, max_n) rep(k, max_n) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cout << f(a[1], a[2], a[3]) << endl;
    return 0;
}