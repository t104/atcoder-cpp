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
    string a;
    cin >> a;
    int n = a.size();
    int ans = 0;
    int dif = 0;
    rep(i,n) {
        if (a[i] != a[n-1-i]) dif++;
    }
    if (2 < dif) {
        cout << 25*n << endl;
        return 0;
    }
    rep(i,n) {
        if (i == n-1-i) {
            if (dif != 0) ans += 25;
        }
        else if (a[i] == a[n-1-i]){
            ans += 25;
        }
        else {
            ans += 24;
        }
    }
    cout << ans << endl;
    return 0;
}