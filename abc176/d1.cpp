#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> s(h);
    for (auto &i : s) cin >> i;
    vector<vector<int>> grid(h, vector<int>(w, MOD));
    deque<P> que;
    que.push_back({sy, sx});
    grid.at(sy).at(sx) = 0;
    vector<int> dir = { 1, 0, -1, 0, 1 };
    while (!que.empty()) {
        int cy, cx;
        tie(cy, cx) = que.front();
        que.pop_front();
        rep(i,4) {
            int ny = cy + dir.at(i);
            int nx = cx + dir.at(i+1);
            if (ny < 0 || nx < 0 || h <= ny || w <= nx) continue;
            if (s.at(ny).at(nx) == '#') continue;
            if (grid.at(cy).at(cx) < grid.at(ny).at(nx)) {
                grid.at(ny).at(nx) = grid.at(cy).at(cx);
                que.push_front({ ny, nx });
            }
        }
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                int ny = cy + i;
                int nx = cx + j;
                if (ny < 0 || nx < 0 || h <= ny || w <= nx) continue;
                if (s.at(ny).at(nx) == '#') continue;
                if (grid.at(cy).at(cx) + 1 < grid.at(ny).at(nx)) {
                    grid.at(ny).at(nx) = grid.at(cy).at(cx) + 1;
                    que.push_back({ ny, nx });
                }
            }
        }
    }
    if (grid.at(gy).at(gx) == MOD) grid.at(gy).at(gx) = -1;
    cout << grid.at(gy).at(gx) << endl;
    return 0;
}