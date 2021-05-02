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

int h, w;

vector<vector<int>> a, b;

struct dijkstra {
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> dist;

    dijkstra() {
        dist.resize(h*w*2, INF);
    }

    int zip(int hi, int wi, int fi) {
        return 2*(hi*w + wi) + fi;
    }

    tuple<int, int, int> unzip(int x) {
        int fi = x%2;
        int wi = x/2%w;
        int hi = x/(w*2);
        return tie(hi, wi, fi);
    }

    void push(int hi, int wi, int fi, int d) {
        int x = zip(hi, wi, fi);
        if (dist[x] <= d) return;
        dist[x] = d;
        que.emplace(d, zip(hi, wi, fi));
    }

    tuple<int, int, int, int> pop() {
        auto [d, x] = que.top(); que.pop();
        auto [hi, wi, fi] = unzip(x);
        return tie(hi, wi, fi, d);
    }

    void run(int sh, int sw) {
        push(sh, sw, 0, 0);
        while (!que.empty()) {
            auto [hi, wi, fi, d] = pop();
            
            if (fi == 0) {
                if (wi+1 < w) push(hi, wi+1, fi, d + a[hi][wi]);
                if (0 < wi) push(hi, wi-1, fi, d + a[hi][wi-1]);
                if (hi+1 < h) push(hi+1, wi, fi, d + b[hi][wi]);
                push(hi, wi, fi+1, d+1);
            }
            else {
                if (0 < hi) push(hi-1, wi, fi, d+1);
                push(hi, wi, 0, d);
            }
        }
    }

    int get(int hi, int wi) {
        return dist[zip(hi, wi, 0)];
    }
};

int main() {
    cin >> h >> w;
    a.resize(h, vector<int>(w-1));
    b.resize(h-1, vector<int>(w));
    rep(i,h) rep(j,w-1) cin >> a[i][j];
    rep(i,h-1) rep(j,w) cin >> b[i][j];

    dijkstra dks;
    dks.run(0, 0);
    int ans = dks.get(h-1, w-1);
    cout << ans << endl;
    return 0;
}