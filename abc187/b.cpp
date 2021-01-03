#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    int ans = 0;
    rep(i,n) {
        for (int j = i+1; j<n; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if (dx < 0) dx *= -1;
            if (-dx <= dy && dy <= dx) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}