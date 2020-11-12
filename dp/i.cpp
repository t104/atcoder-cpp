#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<long double> p(n+1);
    for (int i = 1; i <= n; ++i) cin >> p.at(i);
    cout << std::fixed << std::setprecision(15);
    
    vector<vector<long double>> dp(n+1, vector<long double>(n+1));
    dp.at(0).at(0) = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp.at(i).at(j) += dp.at(i-1).at(j) * ((long double) 1 - p.at(i));
            if (0 < j) dp.at(i).at(j) += dp.at(i-1).at(j-1) * p.at(i);
        }
    }
    long double ans = 0;
    for (int i = n/2 + 1; i <= n; ++i)
        ans += dp.at(n).at(i);
    cout << ans << endl;
    return 0;
}