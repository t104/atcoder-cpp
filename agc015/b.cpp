#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    int n = s.size();
    rep(i,n) {
        if (s.at(i) == 'U') {
            ans += 2 * i;
            ans += n - (i+1);
        }
        if (s.at(i) == 'D') {
            ans += 2 * (n - (i+1));
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}