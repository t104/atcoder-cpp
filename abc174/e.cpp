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

const int MX = 20005;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int r = INF;
    int l = 0;
    auto ok = [&](int x) {
        int cnt = 0;
        rep(i,n) {
            if (a[i] <= x) continue;
            cnt += a[i]/x;
            if (a[i]%x == 0) cnt--;
            if (k < cnt) {
                return false;
            }
        }
        return true;
    };

    while (l+1 < r) {
        int m = (l+r)/2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout << r << endl;

    return 0;
}