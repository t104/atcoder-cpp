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
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<ll> dif(n);
    rep(i,n) {
        dif[i] += 2*a[i] + b[i];
    }
    sort(dif.rbegin(), dif.rend());

    ll d = 0;
    rep(i,n) d -= a[i];
    int idx = 0;
    while (d <= 0) {
        d += dif.at(idx);
        idx++;
    }
    cout << idx << endl;
    return 0;
}