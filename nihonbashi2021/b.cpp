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

int n;
vector<vector<int>> ex;
vector<P> direction = {
    {1,1}, {1,-1}, {-1, 1}, {-1, -1}
};

const clock_t LIMIT = 1.9 * CLOCKS_PER_SEC;
clock_t start;

struct powers {
    vector<vector<int>> ans;
    int score;
    mt19937 mt;
    vector<P> larger;
    int range = 1000;

    powers() {
        ans.resize(n, vector<int>(n));
        random_device rd;
        mt = mt19937(rd());
        rep(i,n) rep(j,n) {
            larger.emplace_back(i, j);
        }
        sort(larger.rbegin(), larger.rend());
    }

    void increment_range() {
        if (range < n*n) range++;
    }

    bool is_inside(int p, int q) {
        return in(p, 0, n) && in(q, 0, n);
    }

    void up(int p, int q, int d) {
        ans[p][q] += d;
        score += d * ex[q][q];
    }

    int dist(int p1, int q1, int p2, int q2) {
        return abs(p1-p2) + abs(q1-q2);
    }

    void up_if_better(int p, int q, int d) {
        if (40 < ans[p][q] + d) return;
        int dif = 0;
        vector<P> overlaps;
        rep(i,n) {
            rep(j,n) {
                if (i == p && j == q) continue;
                if (ans[i][j] == 0) continue;
                if (dist(i, j, p, q) <= max(ans[i][j], ans[p][q] + d)) {
                    dif += ans[i][j] * ex[i][j];
                    overlaps.emplace_back(i, j);
                }
            }
        }
        if (ex[p][q] * d <= dif) return;
        for (auto [i, j]: overlaps) {
            up(i, j, -ans[i][j]);
        }
        up(p, q, d);
    }

    void up_random() {
        int idx = mt() % range;
        up_if_better(larger[idx].first, larger[idx].second, 1);
    }

    void print() {
        rep(i,n) {
            rep(j, n) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    cin >> n;
    ex.resize(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> ex[i][j];
    powers pw;
    int counter = 0;
    while (true) {
        clock_t t = clock() - start;
        if (LIMIT < t) {
            pw.print();
            return 0;
        }
        if (counter == 1000) {
            pw.increment_range();
            counter = 0;
        }
        pw.up_random();
        counter++;
    }
    return 0;
}