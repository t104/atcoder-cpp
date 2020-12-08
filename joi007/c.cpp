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
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n+1);
    rep(i,n) cin >> a.at(i);
    vector<ll> b;
    rep(i,n+1) {
        for (int j = i+1; j < n+1; ++j) {
            b.push_back(a.at(i) + a.at(j));
        }
    }

    ll ans = 0;
    sort(b.begin(), b.end());
    int bn = (int) b.size();
    for (auto bi : b) {
        int l = 0, r = bn-1;
        if (b.at(r) < m - bi) {
            chmax(ans, bi + b.at(r));
            continue;
        }
        if (m - bi < b.at(l)) {
            if (bi <= m) chmax(ans, bi);
            continue;
        }
        while (1 < r-l) {
            int mid = (l+r) / 2;
            if (m - bi < b.at(mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        chmax(ans, bi + b.at(l));
    }
    cout << ans << endl;
    return 0;
}