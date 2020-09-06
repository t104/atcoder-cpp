#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    int ans = 0;
    rep(i,h) cin >> s[i];
    rep(is, 1<<h) rep(js, 1<<w) {
        int cnt = 0;
        rep(i,h) rep(j,w) {
            if (is>>i&1) continue;
            if (js>>j&1) continue;
            if (s[i][j] == '#') cnt++;
        }
        if (cnt == k) ans++;
    }
    cout << ans << endl;
    return 0;
}