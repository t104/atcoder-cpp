#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int mod = 1000000007;

int N;
vector<int> G[100009];
long long white[100009], black[100009];

void dfs(int u, int p) {
    black[u] = 1;
    white[u] = 1;
    for(int v : G[u]) {
        if(v == p) continue; // 親に帰る辺は無視
        dfs(v, u);
        black[u] *= white[v];
        black[u] %= mod;
        white[u] *= white[v] + black[v];
        white[u] %= mod;
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--; // 0-indexed にする
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(0, -1);

    rep(i,N) cout << white[i] << ' ';
    cout << endl;
    rep(i,N) cout << black[i] << ' ';
    cout << endl;

    cout << (black[0] + white[0]) % mod << endl;

    return 0;
}