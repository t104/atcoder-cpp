#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;
const int max_n = 10005;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(10);
    rep(i,k) {
        int di;
        cin >> di;
        d.at(di) = 1;
    }
    while (true) {
        string ns = to_string(n);
        bool ok = true;
        for (char c : ns) {
            if (d.at(c-'0') == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << n << endl;
            return 0;
        }
        n++;
    }
    return 0;
}