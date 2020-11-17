#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;
const int max_n = 100009;
int n;
vector<vector<int>> G(max_n);
vector<mint> white(max_n), black(max_n);

void dfs(int now, int parent) {
    white[now] = 1;
    black[now] = 1;
    for (auto next : G[now]) {
        if (next == parent) continue;
        dfs(next, now);
        black[now] *= white[next];
        white[now] *= white[next] + black[next];
    }
}

int main() {
    cin >> n;
    rep(i,n-1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G.at(x).push_back(y);
        G.at(y).push_back(x);
    }

    dfs(0, -1);

    cout << (white[0] + black[0]).val() << endl;

    return 0;
}