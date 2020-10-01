#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    string s;
    cin >> s;
    int n = s.size();
    char c = s.at(0);
    int ans = 0;
    rep(i,n) {
        if (s.at(i) != c) ans++;
        c = s.at(i);
    }
    cout << ans << endl;
    return 0;
}