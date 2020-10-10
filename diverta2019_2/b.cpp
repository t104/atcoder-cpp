#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

P dif (P x, P y) { return {x.first - y.first, x.second - y.second}; }

int main() {
    int n;
    cin >> n;
    vector<P> balls(n);
    rep(i,n) cin >> balls.at(i).first >> balls.at(i).second;

    int ans = n;
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            P d = dif(balls.at(i), balls.at(j));
            int count = n;
            rep(k,n) {
                for (int l = k+1; l < n; ++l) {
                    if (dif(balls.at(k), balls.at(l)) == d) count--;
                    if (dif(balls.at(l), balls.at(k)) == d) count--;
                }
            }
            chmin(ans, count);
        }
    }

    cout << ans << endl;
    return 0;
}