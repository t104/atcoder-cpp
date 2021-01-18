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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(MX);
    rep(i,n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    ll ans = 0;
    rep(i,MX) {
        chmin(k, cnt[i]);
        ans += k;
    }
    cout << ans << endl;
    return 0;
}