#include <algorithm>
#include <atcoder/all>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using mint = atcoder::modint1000000007;
using mint2 = atcoder::modint998244353;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

int n;
vector<P> edge[110000];
int u, v, c;

bool come[110000];
int col[110000];
void dfs(int x, bool done = false, int color = 1)
{
    //    cout << x << " " << done << " " << color << endl;
    set<int> ban = {color};
    come[x] = true;
    if (!done) {
        col[x] = color;
    }
    else {
        color = -1;
    }

    for (auto [to, label] : edge[x]) {
        if (come[to])
            continue;
        dfs(to, label == color, label);
        ban.insert(label);
    }
    if (done) {
        int c = 1;
        while (ban.count(c))
            c++;
        col[x] = c;
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        edge[u].push_back(P(v, c));
        edge[v].push_back(P(u, c));
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << col[i] << endl;
    return 0;
}