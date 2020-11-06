#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> ans;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a.at(i).at(j);
    rep(i,h) rep(j,w) {
        if (a.at(i).at(j)%2 == 1) {
            if (i < h-1) {
                ans.push_back({i, j, i+1, j});
                a.at(i).at(j)--;
                a.at(i+1).at(j)++;
            }
            else if (j < w-1) {
                ans.push_back({i, j, i, j+1});
                a.at(i).at(j)--;
                a.at(i).at(j+1)++;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto m : ans) {
        rep(i,4) {
            cout << m.at(i) + 1;
            if (i != 3) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}