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
    int n;
    map<int, int> floor;
    rep(i,n) {
        int a, b;
        bool ok = true;
        if (a != -1) {
            if (!floor.count(a)) floor[a] = i;
            else ok = false;
        }
        if (b != -1) {
            if (!floor.count(b)) floor[b] = i;
            else ok = false;
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    

    return 0;
}