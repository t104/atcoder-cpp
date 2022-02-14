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
    int n;
    cin >> n;
    vector<int> a(n), b(n+2);
    rep(i,n) cin >> a[i];
    rep(i,n-1) {
        b[i+3] = b[i] + a[i+1] - a[i];
    }
    rep(_, 3) {
        auto mi = min_element(b.begin(), b.end());
        if (*mi < 0) {
            int i = mi - b.begin();
            int x = *mi;
            for (int j = i; j < n+2; j+=3) {
                b[j] -= x;
            }
            for (int j = i-3; 0 <= j; j-=3) {
                b[j] -= x;
            }
        }
    }
    int d = a[0] - b[0] - b[1] - b[2];
    if (d < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n+2; i+=3) b[i] += d;
    rep(i,n+2) cout << b[i] << ' ';
    cout << endl;
    return 0;
}


