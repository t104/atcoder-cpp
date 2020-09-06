#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s.at(i);

    vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};
    rep(i, h) {
        rep(j, w) {
            if(s.at(i).at(j) == '.') continue;
            int ok = false;
            rep(k, 4) {
                int xi = j + dx.at(k);
                int yi = i + dy.at(k);
                if(0 <= xi && xi < w && 0 <= yi && yi < h && s.at(yi).at(xi) == '#') {
                    ok = true;
                    break;
                }
            }
            if(!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}