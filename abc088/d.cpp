#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    vector<vector<int>> mp(h,vector<int>(w, -1));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<P> q;
    q.push({0,0});
    mp.at(0).at(0) = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        rep(i, 4) {
            int nx = x + dx.at(i);
            int ny = y + dy.at(i);
            if (0 <= nx && nx < h && 0 <= ny && ny < w && mp.at(nx).at(ny) == -1 && s.at(nx).at(ny) == '.') {
                mp.at(nx).at(ny) = mp.at(x).at(y) + 1;
                q.push({nx, ny});
            }
        }
    }
    int step = mp.at(h-1).at(w-1);
    int black = 0;
    rep(i,h) rep(j,w) {
        if (s.at(i).at(j) == '#') black++;
    }
    if (step == -1) cout << -1 << endl;
    else cout << h*w - (step+1) - black << endl;
    return 0;
}