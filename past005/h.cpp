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
const char dc[] = { '<' , '^' , '>' , 'v' };
const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};

int h, w;
int r, c;
vector<string> s;

int main() {
    cin >> h >> w >> r >> c;
    --r, --c;
    s.resize(h);
    rep(i,h) cin >> s.at(i);
    vector<string> ans(h, string(w, 'x'));
    rep(i,h) rep(j,w) if (s.at(i).at(j) == '#') ans.at(i).at(j) = '#';
    queue<P> que;
    que.emplace(r,c);
    ans.at(r).at(c) = 'o';
    while(!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        rep(i,4) {
            int nx = x + dh[i];
            int ny = y + dw[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && s.at(nx).at(ny) != '#' && ans.at(nx).at(ny) != 'o') {
                if (s.at(nx).at(ny) == '.' || s.at(nx).at(ny) == dc[i]) {
                    ans.at(nx).at(ny) = 'o';
                    que.emplace(nx, ny);
                }
            }
        }
    }
    rep(i,h) {
        cout << ans.at(i) << endl;
    }

    return 0;
}