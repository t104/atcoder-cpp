#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> snk(n, false);
    rep(i, k) {
        int d;
        cin >> d;
        rep(j, d) {
            int a;
            cin >> a;
            a--;
            snk.at(a) = true;
        }
    }
    int ans = 0;
    rep(i, n) {
        if(!snk.at(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}