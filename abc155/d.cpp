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
using P = pair<ll,int>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = -LINF, r = LINF;
    while (l+1 < r) {
        ll x = (l+r)/2;
        auto ok = [&](){
            // x 未満が何個あるか
            ll tot = 0;
            rep(i,n) {
                if (a[i] < 0) {
                    // a[i] が負のとき、
                    // a[i]*a[j] > a[i]*a[j+1]
                    int l = -1, r = n;
                    while (l+1 < r) {
                        int m = (l+r)/2;
                        if (a[m] * a[i] < x) {
                            r = m;
                        }
                        else {
                            l = m;
                        }
                    }
                    // a[r], ... a[n] が x 未満
                    tot += n - r;
                }
                else {
                    // a[i] が正のとき、
                    // a[i]*a[j] < a[i]*a[j+1]
                    int l = -1, r = n;
                    while (l + 1 < r) {
                        int m = (l+r)/2;
                        if (a[m] * a[i] < x) {
                            l = m;
                        }
                        else {
                            r = m;
                        }
                    }
                    // a[0], ... a[r-1] が x 未満
                    tot += r;
                }
                // 自分自身とのペアを引く
                if (a[i]*a[i] < x) tot--;
            }
            tot /= 2;
            return tot < k;
        };
        if (ok()) l = x;
        else r = x;
    }
    cout << l << endl;
    return 0;
}