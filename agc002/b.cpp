#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    rep(i,m) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--; y.at(i)--;
    }
    
    vector<P> box(n);
    box.at(0) = {1,1};
    for (int i = 1; i < n; ++i) box.at(i) = {0, 1};
    rep(i,m) {
        int xi = x.at(i);
        int yi = y.at(i);
        if (0 < box.at(xi).first) {
            box.at(yi).first = 1;
        }
        if (box.at(xi).second == 1) {
            box.at(xi).first = 0;
        }
        box.at(xi).second--;
        box.at(yi).second++;
    }
    int ans = 0;
    rep(i,n) {
        if (0 < box.at(i).first) ans++;
    }
    cout << ans << endl;
    return 0;
}