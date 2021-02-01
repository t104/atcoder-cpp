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

const int MX = 300005;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]++;
    }

    fenwick_tree<ll> t(MX);

    ll cnt = 0;
    rep(i,n) {
        cnt += t.sum(a[i]+1,MX);
        t.add(a[i], 1);
    }

    rep(i,n) {
        cout << cnt << endl;
        cnt -= a[i];
        cnt += (ll) n+1-a[i];
    }
    
    return 0;
}