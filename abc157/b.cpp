#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    map<int, P> m;
    rep(i, 3) {
        rep(j, 3) {
            int k;
            cin >> k;
            m[k] = make_pair(i, j);
        }
    }
    int n;
    cin >> n;
    vector<vector<bool>> bingo(3, vector<bool>(3, false));
    rep(i, n) {
        int j;
        cin >> j;
        if(m.count(j)) {
            P col = m.at(j);
            bingo.at(col.first).at(col.second) = true;
        }
    }

    rep(i, 3) {
        bool h = true;
        bool v = true;
        rep(j, 3) {
            h = h & bingo.at(i).at(j);
            v = v & bingo.at(j).at(i);
        }
        if(h || v) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    bool up = true;
    bool down = true;
    rep(i, 3) {
        up = up && bingo.at(i).at(i);
        down = down && bingo.at(2-i).at(i);
    }
    if(up || down) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}