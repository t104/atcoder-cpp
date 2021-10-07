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

const double EPS = 1e-5;

int main() {
    int ax, ay, bx, by;
    int n;
    cin >> ax >> ay >> bx >> by >> n;
    int dx = ax - bx, dy = ay - by;
    vector<int> X(n), Y(n);
    rep(i,n) cin >> X[i] >> Y[i];
    int tot = 0;
    rep(i,n) {
        int dxi = X[i] - X[(i+1)%n], dyi = Y[i] - Y[(i+1)%n];
        ll s1 = dy * (ax - X[i]) - dx * (ay - Y[i]);
        ll s2 = dy * (ax - X[(i+1)%n]) - dx * (ay - Y[(i+1)%n]);
        ll s3 = dyi * (X[i] - ax) - dxi * (Y[i] - ay);
        ll s4 = dyi * (X[i] - bx) - dxi * (Y[i] - by);
        if (s1 * s2 < 0 && s3 * s4 < 0) tot++;
    }
    cout << tot / 2 + 1 << endl;
    return 0;
}