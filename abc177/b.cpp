#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;

    int ans = 1e9;
    int ns = s.size();
    int ts = t.size();
    rep(i, ns-ts+1) {
        string sub = s.substr(i,ts);
        int count = 0;
        rep(j,ts) {
            if (sub.at(j) != t.at(j)) count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
    return 0;
}