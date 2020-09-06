#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    rep(i, h) cin >> mp.at(i);

    vector<vector<int>> bomb(h, vector<int>(w));
    vector<pair<int, int>> dif = {
        make_pair(-1, -1), make_pair(-1, 0),
        make_pair(-1, 1), make_pair(0, -1),
        make_pair(0, 1), make_pair(1, -1),
        make_pair(1, 0), make_pair(1, 1)
    };
    rep(i, h) {
        rep(j, w) {
            if(mp.at(i).at(j) == '#') {
                bomb.at(i).at(j) = -1;
                for(auto d : dif) {
                    int di = i + d.first;
                    int dj = j + d.second;
                    if(0 <= di && di < h && 0 <= dj && dj < w && bomb.at(di).at(dj) != -1) {
                        bomb.at(di).at(dj)++;
                    }
                }
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            if(bomb.at(i).at(j) == -1) {
                cout << '#';
            }
            else cout << bomb.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}