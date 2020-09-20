#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> white(n);
    rep(i, q) {
        int command, x;
        cin >> command >> x;
        if (command == 1) {
            rep(i, n) white.at(i).push_back(x);
        }
    }
    return 0;
}