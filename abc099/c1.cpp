#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    int ans = INF;
    for (int i = 0; i <= n; ++i) {
        int t = i, count = 0;
        while (0 < t) {
            count += t % 6;
            t /= 6;
        }
        t = n - i;
        while (0 < t) {
            count += t % 9;
            t /= 9;
        }
        chmin(ans, count);
    }
    cout << ans << endl;
    return 0;
}