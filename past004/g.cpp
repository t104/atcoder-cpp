#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int n, m;
vector<string> input;
const int dw[] = {1, 0, -1, 0};
const int dh[] = {0, 1, 0, -1};
bool ok(vector<vector<int>> grid, int wall) {
    rep(i,n) rep(j,m) {
        if (grid.at(i).at(j) == -1) continue;
        queue<P> que;
        que.push({i,j});
        int count = 1;
        grid.at(i).at(j) = count;
        while (!que.empty()) {
            int h = que.front().first;
            int w = que.front().second;
            que.pop();
            rep(k,4) {
                int nh = h + dh[k];
                int nw = w + dw[k];
                if (0 <= nh && nh < n && 0 <= nw && nw < m && grid.at(nh).at(nw) == 0) {
                    ++count;
                    grid.at(nh).at(nw) = count;
                    que.push({nh, nw});
                }
            }
        }
        return count + wall == n * m;
    }
    return true;
}

int main() {
    cin >> n >> m;
    input.resize(n);
    vector<vector<int>> grid(n, vector<int>(m));
    rep(i,n) cin >> input.at(i);
    vector<P> walls;
    rep(i,n) rep(j,m) if(input.at(i).at(j) == '#') walls.push_back({i,j});
    for (auto w : walls) grid.at(w.first).at(w.second) = -1;
    int ans = 0;
    for (auto w : walls) {
        grid.at(w.first).at(w.second) = 0;
        if (ok(grid, (int) walls.size() - 1)) ans++;
        grid.at(w.first).at(w.second) = -1;
    }
    cout << ans << endl;
    return 0;
}