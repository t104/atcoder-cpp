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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(1,1);
    rep(i,n-1) {
        if (a[i+1] != a[i]) {
            cnt.back()++;
        }
        else {
            cnt.push_back(1);
        }
    }

    int ans = 0;
    int s = cnt.size();
    chmax(ans, cnt[0]);
    if (2 <= s) {
        chmax(ans, cnt[0] + cnt[1]);
    }
    rep(i,s-2) {
        chmax(ans, cnt[i] + cnt[i+1] + cnt[i+2]);
    }
    cout << ans << endl;
    return 0;
}