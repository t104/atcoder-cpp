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
using P = pair<ll,ll>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<P> money(n);
    rep(i,n) {
        cin >> money[i].first >> money[i].second;
    }
    sort(money.begin(), money.end());
    
    ll p = 0;
    rep(i,n) {
        if (k < money[i].first - p) {
            cout << p+k << endl;
            return 0;
        }
        k -= money[i].first - p;
        k += money[i].second;
        p = money[i].first;
    }
    cout << p+k << endl;
    return 0;
}