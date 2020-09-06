#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c.at(i);

    rep(i, h) {
        cout << c.at(i) << endl;
        cout << c.at(i) << endl;
    }

    return 0;
}