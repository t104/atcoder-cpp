#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a.at(i);
    vector<P> black;
    int ans = 0;
    rep(i,h) rep(j,w) {
        if (a.at(i).at(j) == '#') black.push_back({i,j});
    }
    vector<P> d = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    while (black.size()) {
        vector<P> next;
        for (auto now : black) {
            for (auto di : d) {
                int nh = now.first + di.first;
                int nw = now.second + di.second;
                if (0 <= nh && nh < h && 0 <= nw && nw < w && a.at(nh).at(nw) == '.') {
                    a.at(nh).at(nw) = '#';
                    next.push_back({nh, nw});
                }
            }
        }
        ans++;
        swap(black, next);
    }
    ans--;
    cout << ans << endl;
    return 0;
}