#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    cout << std::fixed << std::setprecision(15);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i,n) cin >> l[i] >> r[i];

    double ex = 0.;
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            ll tot = (r[i]-l[i]+1) * (r[j]-l[j]+1);
            ll cnt = 0;
            for (int k = l[j]; k <= r[j]; ++k) {
                cnt += max(0, r[i] - max(l[i] -  1, k));
            }
            ex += (double) cnt / tot;
        }
    }
    cout << ex << endl;

    return 0;
}