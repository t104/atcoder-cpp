#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    int n;
    cin >> s >> n;
    int sn = s.size();
    int all = 'z' - 'a' + 1;
    rep(i,sn) {
        if (n == 0) break;
        char c = s.at(i);
        if (c == 'a') continue;
        int to_a = 'z' - c + 1;
        if (to_a <= n) {
            s.at(i) = 'a';
            n -= to_a;
        }
    }
    if (0 < n) {
        n %= all;
        s.at(sn-1) += n;
    }
    cout << s << endl;
    return 0;
}