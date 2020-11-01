#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    ll key = -1;
    for (ll i = 0; i < n; ++i) cin >> x.at(i) >> y.at(i) >> h.at(i);
    for (ll i = 0; i < n; ++i)
        if (h[i] > 0) key = i;
    for (ll cx = 0; cx < 101; ++cx) {
            for (ll cy = 0; cy < 101; ++cy) {
            ll height = h[key] + abs(cx - x[key]) + abs(cy - y[key]);
            chmax(height,0LL);
            for (ll i = 0; i < n; ++i) {
                ll tmp = height - abs(x.at(i) - cx) - abs(y.at(i) -cy);
                chmax(tmp, 0LL);
                if (tmp != h.at(i)) break;
                if (i == n-1) {
                    cout << cx << " " << cy << " " << height << endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}