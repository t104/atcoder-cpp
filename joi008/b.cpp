#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> D(n), K(m);
    for (int i = 1; i < n; ++i) cin >> D[i];
    rep(i,m) cin >> K[i];
    ll ans = 0;
    sort(D.begin(), D.end());
    rep(i,m) {
        int index = lower_bound(D.begin(), D.end(), K[i]) - D.begin();
        if (index < n) {
            ans += min(abs(D[index] - K[i]), abs(D[index-1] - K[i]));
        }
        else {
            ans += min(abs(D[n-1] - K[i]), abs(d - K[i]));
        }
    }
    cout << ans << endl;
    return 0;
}