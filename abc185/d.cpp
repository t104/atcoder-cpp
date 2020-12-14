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
const ll LINF = 1LL<<60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a.at(i);
    rep(i,m) --a.at(i);
    sort(a.begin(), a.end());

    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }

    int k = INF;
    rep(i,m-1) {
        int l = a.at(i+1) - a.at(i) - 1;
        if (0 < l) chmin(k, l);
    }
    if (0 < a.at(0)) chmin(k, a.at(0));
    if (0 < n - 1 - a.at(m-1)) chmin(k, n - 1 - a.at(m-1));
    int ans = 0, idx = 0;
    rep(i,m) {
        ans += (a.at(i) - idx) / k;
        if (0 < (a.at(i) - idx) % k) {
            ans++;
        }
        idx = a.at(i) + 1;
    }
    ans += (n - idx) / k;
    if (0 < (n - idx) % k) ans++;
    cout << ans << endl;
    return 0;
}