#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> maze (h, vector<int>(w, -1));
    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            if (c == '#') maze.at(i).at(j) = 1001001001;
        }
    }

    int ans = 0;
    vector<P> step = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    rep(i, h) {
        rep(j, w) {
            if (maze.at(i).at(j) == -1) {
                queue<P> q;
                vector<vector<int>> m = maze;
                m.at(i).at(j) = 0;
                int d = 0;
                q.push({i, j});
                while (!q.empty()) {
                    P now = q.front(); q.pop();
                    d = max(d, m.at(now.first).at(now.second));
                    for (auto s : step) {
                        int x = now.first + s.first;
                        int y = now.second + s.second;
                        if (0 <= x && x < h && 0 <= y && y < w && m.at(x).at(y) == -1) {
                            m.at(x).at(y) = m.at(now.first).at(now.second) + 1;
                            q.push({x, y});
                        }
                    }
                }
                ans = max(ans, d);
            }
        }
    }

    cout << ans << endl;
    return 0;
}