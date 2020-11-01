#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    ll key = -1;
    for (ll i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];
    for (ll i = 0; i < n;i++)
        if (h[i] > 0) key = i;
    for (ll cx = 0; cx < 101; cx++) {
        for (ll cy = 0; cy < 101;cy++){
            ll height = h[key] + abs(cx - x[key]) + abs(cy - y[key]);
            chmax(height, 0LL);
            for (ll i = 0; i < n;i++){
                ll tmp = height - abs(x[i] - cx) - abs(y[i] - cy);
                chmax(tmp, 0LL);
                if (tmp != h[i]) break;
                if(i==n-1){
                    cout << cx << " " << cy << " " << height << endl;
                    return 0;
                }
            }
        }
    }
}