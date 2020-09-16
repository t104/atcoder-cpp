#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> cake(h,vector<int>(w));
    vector<string> berry(h);
    rep(i, h) cin >> berry.at(i);

    int ki = 0;
    rep(i, h) {
        int l = 0;
        rep(j, w) {
            if (berry.at(i).at(j) == '#') {
                ki++;
                for (int a = l; a <= j; ++a) {
                    cake.at(i).at(a) = ki;
                }
                l = j + 1;
            }
            else if (l != 0 && j == w-1) {
                for (int a = l; a <= j; ++a) {
                    cake.at(i).at(a) = ki;
                }
            }
        }
    }

    rep(i, w) {
        rep(j, h) {
            for (int k = j; k < h; ++k) {
                if (cake.at(j).at(i) != 0) break;
                cake.at(j).at(i) = cake.at(k).at(i);
            }
            for (int k = j; 0 <= k; --k) {
                if (cake.at(j).at(i) != 0) break;
                cake.at(j).at(i) = cake.at(k).at(i);
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << cake.at(i).at(j);
            if (j < w-1) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}