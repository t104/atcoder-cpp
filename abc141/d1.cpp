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
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<ll> a;
    rep(i,n) {
        ll ai;
        cin >> ai;
        a.push(ai);
    }
    rep(i,m) {
        ll ai = a.top(); a.pop();
        a.push(ai/2);
    }
    ll ans = 0;
    while (!a.empty()) {
        ans += a.top(); a.pop();
    }
    cout << ans << endl;
    return 0;
}