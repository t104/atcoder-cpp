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

enum task_status {
    not_ready,
    ready,
    processing,
    done
};

struct task {
    int id;
    task_status status;
    vector<int> depends_on;
    vector<int> needed_for;
    task(int id): id(id) {
        status = not_ready;
    }
};

int main() {
    int N, M, K, R;
    cin >> N >> M >> K >> R;
    vector<vector<int>> d(N, vector<int>(K));
    vector<task> tasks;
    rep(i,N) rep(j,K) cin >> d[i][j];
    rep(i,N) {
        tasks.emplace_back(i);
    }
    rep(i,R) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tasks[v].needed_for.push_back(u);
        tasks[u].depends_on.push_back(v);
    }
    vector<int> assignment(M, -1);
    while (true) {
        vector<P> task_start;
        rep(i,M) {
            if (assignment[i] != -1) continue;
            for (int j = 0; j < N; ++j) {
                if (tasks[j].status == not_ready) {
                    task_status new_status = ready;
                    for (auto &needed : tasks[j].needed_for) {
                        if (tasks[needed].status != done) {
                            new_status = not_ready;
                        }
                    }
                    tasks[j].status = new_status;
                }
                if (tasks[j].status == ready) {
                    assignment[i] = j;
                    task_start.emplace_back(i, j);
                    tasks[j].status = processing;
                    break;
                }
            }
        }
        cout << task_start.size() << ' ';
        for (auto &[a, b] : task_start) {
            cout << a+1 << ' ' << b+1 << ' ';
        }
        cout << endl;
        int n;
        cin >> n;
        if (n == -1) {
            return 0;
        }
        rep(i,n) {
            int member;
            cin >> member;
            tasks[assignment[member - 1]].status = done;
            assignment[member - 1] = -1;
        }
    }
    return 0;
}