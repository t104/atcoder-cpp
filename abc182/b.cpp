#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    int ans = 0, max_gcd = 0;
    for (int i = 2; i <= 1000; ++i) {
        int gcd = 0;
        rep(j,n) {
            if (a.at(j) % i == 0) gcd++;
        }
        if (max_gcd < gcd) {
            max_gcd = gcd;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}