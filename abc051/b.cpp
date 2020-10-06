#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int k, s;
    cin >> k >> s;
    
    int ans = 0;
    rep(x,k+1) rep(y,k+1) {
        int z = s - x - y;
        if (0 <= z && z <= k) ans++;
    }
    cout << ans << endl;
    return 0;
}