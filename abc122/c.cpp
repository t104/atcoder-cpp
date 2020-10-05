#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> ac(n);
    int idx = -1;
    while (true) {
        idx = s.find("AC", idx+1);
        if (idx == string::npos) break;
        ac.at(idx+1) = 1;
    }
    for (int i = 1; i < n; ++i) {
        ac.at(i) += ac.at(i-1);
    }
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        l--; r--;
        if (0 <= l && r < n) ans = ac.at(r) - ac.at(l);
        cout << ans << endl;
    }
    return 0;
}