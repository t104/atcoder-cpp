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
using Graph = vector<vector<int>>;

vector<bool> seen, finished;
vector<vector<int>> g;
vector<vector<int>> rvg;
vector<int> A, B;
int n, m, k;

void dame() {
    cout << -1 << endl;
    exit(0);
}

void dfs(int v, deque<int> &que) {
    seen[v] = true;
    que.push_back(v);

    for (auto nv: g[v]) {
        if (finished[nv]) continue;
        if (seen[nv]) {
            dame();
        }
        dfs(nv, que);
    }
    finished[v] = true;
}

void rvdfs(int v, deque<int> &que) {
    seen[v] = true;
    if (que.front() != v) que.push_front(v);

    for (auto nv: rvg[v]) {
        if (finished[nv]) continue;
        if (seen[nv]) {
            dame();
        }
        rvdfs(nv, que);
    }
    finished[v] = true;
}

void test(vector<vector<int>> &ans) {
    for (auto &ai: ans) {
        vector<int> order(n);
        rep(i,n) {
            order[ai[i]] = i;
        }
        rep(i,m) {
            assert(order[A[i]] < order[B[i]]);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    g.resize(n);
    rvg.resize(n);
    A.resize(n);
    B.resize(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        A[i] = a;
        B[i] = b;
        g[a].push_back(b);
        rvg[b].push_back(a);
    }

    seen.assign(n, false);
    finished.assign(n, false);
    vector<deque<int>> groups;
    rep(i,n) {
        if (seen[i]) continue;
        deque<int> que;
        dfs(i, que);
        seen[i] = false;
        finished[i] = false;
        rvdfs(i, que);
        groups.push_back(que);
    }
    vector<int> order;
    int sz = groups.size();
    rep(i,sz) {
        for (auto &j: groups[i]) {
            order.push_back(i);
        }
    }

    vector<vector<int>> ans;
    do {
        vector<int> idx(sz);
        vector<int> ai(n);
        rep(i,n) {
            ai[i] = groups[order[i]][idx[order[i]]];
            idx[order[i]]++;
        }
        ans.push_back(ai);
        --k;
    } while (next_permutation(order.begin(), order.end()) && k);

    test(ans);

    if (k == 0) {
        for (auto &ai: ans) {
            for (auto &i: ai) {
                cout << i+1 << ' ';
            }
            cout << endl;
        }
    }
    else {
        dame();
    }

    return 0;
}