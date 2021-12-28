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
using P = pair<int,int>;

int N, M;

struct edge {
    double c;
    int from, to;
    edge(double c, int from, int to) : c(c), from(from), to(to) {}
    bool operator<(const edge &e) const {
        return c < e.c;
    }
    bool operator>(const edge &e) const {
        return e.c < c;
    }
};

int main() {
    cin >> N >> M;
    vector<int> x(N+M), y(N+M), c(N+M);
    rep(i, N+M) {
        cin >> x[i] >> y[i] >> c[i];
    }
    vector<edge> edges;
    rep(i, N+M) {
        for (int j = i + 1; j < N+M; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            double d = sqrt(dx*dx + dy*dy);
            if (c[i] != c[j]) d *= 10;
            edges.emplace_back(d, i, j);
        }
    }
    sort(edges.begin(), edges.end());
    auto use = [&](int x, int flg) {
        if (x < N) return 1;
        x -= N;
        return (flg >> x) & 1;
    };
    double ans = 1e9;
    rep(flg, 1<<M) {
        dsu uf(N + M);
        double sum = 0;
        for (auto &e : edges) {
            if (use(e.from, flg) && use(e.to, flg)) {
                if (uf.same(e.from, e.to)) continue;
                uf.merge(e.from, e.to);
                sum += e.c;
            }
        }
        chmin(ans, sum);
    }
    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
    return 0;
}

