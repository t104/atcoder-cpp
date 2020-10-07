#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> light(m);
    vector<int> p(m);
    rep(i,m) {
        int k;
        cin >> k;
        rep(j,k) {
            int s;
            cin >> s;
            s--;
            light.at(i).push_back(s);
        }
    }
    rep(i,m) cin >> p.at(i);
    
    int ans = 0;
    for (int i = 0; i < (1<<n); ++i) {
        bool ok = true;
        rep(j,m) {
            int sw = 0;
            for (int s : light.at(j)) {
                if ((i>>s)&1) sw++;
            }
            if (sw % 2 != p.at(j)) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}