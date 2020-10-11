#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

const int max_n = 200000;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    set<int> st;
    int ans = 0;
    rep(i,n) {
        st.insert(p.at(i));
        if (p.at(i) != ans) {
            cout << ans << endl;
            continue;
        }
        while (st.count(ans)) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}