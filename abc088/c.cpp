#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    vector<vector<int>> c(3,vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> c.at(i).at(j);

    bool ok = 
    (c.at(0).at(0) - c.at(0).at(1) == c.at(1).at(0) - c.at(1).at(1)) &&
    (c.at(1).at(0) - c.at(1).at(1) == c.at(2).at(0) - c.at(2).at(1)) &&
    (c.at(0).at(1) - c.at(0).at(2) == c.at(1).at(1) - c.at(1).at(2)) &&
    (c.at(1).at(1) - c.at(1).at(2) == c.at(2).at(1) - c.at(2).at(2));

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}