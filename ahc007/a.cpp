#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<double,int>;

const int N = 400;
const int M = 1995;

dsu now(N);
vector<int> x(N), y(N), u(M), v(M), ans(M);
vector<vector<P>> g(N);
vector<double> sorted_dist;
vector<vector<double>> dist(N, vector<double>(N, 1e9));

struct edge {
    int to;
    double dist;

};

bool can_skip(dsu uf, int i) {
    ++i;
    for (; i < M; ++i) {
        uf.merge(u[i], v[i]);
    }
    return uf.groups().size() == 1;
}

double distance(int i, int j) {
    return sqrt(pow((double) x[i] - x[j], 2) + pow((double) y[i] - y[j], 2));
}

bool should_merge(int len, int i) {
    if (now.same(u[i], v[i])) {
        return false;
    }

    if (len < g[u[i]][0].first * 3 || len < g[v[i]][0].first * 3) {
        return true;
    }

    return false;
}

int main() {
    rep(i,N) cin >> x[i] >> y[i];
    rep(i,M) {
        cin >> u[i] >> v[i];
        double d = distance(u[i], v[i]);
        g[u[i]].emplace_back(d, v[i]);
        g[v[i]].emplace_back(d, u[i]);
    }

    rep(i,N) {
        sort(g[i].begin(), g[i].end());
    }

    auto merge = [&](int i) {
        cout << 1 << endl;
        now.merge(u[i], v[i]);
    };
    
    rep(i,M) {
        sorted_dist.push_back(distance(u[i], v[i]));
    }

    sort(sorted_dist.begin(), sorted_dist.end());

    rep(i,M) {
        int len;
        cin >> len;
        if (can_skip(now, i)) {
            if (should_merge(len, i)) {
                merge(i);
            } else {
                cout << 0 << endl;
            }
        } else {
            merge(i);
        }
    }
    return 0;
}