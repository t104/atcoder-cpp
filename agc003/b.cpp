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
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a.at(i-1)%2 == 1 && 0 < a.at(i)) {
            ans++;
            a.at(i-1)--; a.at(i)--;
        }
        ans += a.at(i-1)/2;
    }
    ans += a.at(n-1)/2;
    cout << ans << endl;
    return 0;
}