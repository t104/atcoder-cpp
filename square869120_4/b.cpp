#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const ll LINF = 1LL<<60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> flg(n);
    rep(i,k) flg[i] = 1;
    sort(flg.begin(), flg.end());
    ll ans = LINF;
    do {
        int h = 0;
        ll cost = 0;
        rep(i,n) {
            if (flg[i] == 0) {
                chmax(h, a[i]);
                continue;
            }
            h = max(h+1, a[i]);
            cost += h - a[i];
        }
        chmin(ans, cost);
    } while (next_permutation(flg.begin(), flg.end()));

    cout << ans << endl;
    return 0;
}