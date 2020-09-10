#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const string ok = "POSSIBLE";
const string ng = "IMPOSSIBLE";

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> ship(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ship.at(a).insert(b);
        ship.at(b).insert(a);
    }

    for (int i : ship.at(0)) {
        if (ship.at(i).count(n-1)) {
            cout << ok << endl;
            return 0;
        }
    }

    cout << ng << endl;
    return 0;
}