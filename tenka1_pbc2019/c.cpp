#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int b = 0, w = 0;
    rep(i, n) {
        if (s.at(i) == '.') w++;
    }
    int ans = w;
    rep(i, n) {
        if (s.at(i) == '.') w--;
        if (s.at(i) == '#') b++;
        ans = min(ans, b + w);
    }
    cout << ans << endl;
    return 0;
}