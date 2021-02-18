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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll ans = 0;
    rep(i,n) cin >> v[i];
    // 最大 i 個捨てる
    rep(i,k/2 + 1) {
        // 左から l 個取る
        rep(l, min(n, k-i+1)) {
            ll sum = 0;
            priority_queue<ll, vector<ll>, greater<ll>> que;
            rep(li, l) {
                sum += v[li];
                que.push(v[li]);
            }
            // 右から k-i-l 個取る
            for (int r = 1; l+r <= min(n, k-i); ++r) {
                sum += v[n-r];
                que.push(v[n-r]);
            }

            // 最大 i 個捨てる
            rep(j,i) {
            if (0 < que.top()) break;
                sum -= que.top(); que.pop();
            }
            chmax(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}