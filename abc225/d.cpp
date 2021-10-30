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

struct train {
    int from, to;
    train(int from = -1, int to = -1): from(from), to(to) {}
};

vector<train> trains;

void to_top(int v, deque<int> &que) {
    if (trains[v].from == -1) {
        return;
    }
    que.push_front(trains[v].from);
    to_top(trains[v].from, que);
}

void to_end(int v, deque<int> &que) {
    if (trains[v].to == -1) {
        return;
    }
    que.push_back(trains[v].to);
    to_end(trains[v].to, que);
}

void print_train(int v) {
    deque<int> que;
    que.push_back(v);
    to_top(v, que);
    to_end(v, que);
    cout << que.size() << ' ';
    for (auto &t: que) cout << t+1 << ' ';
    cout << endl;
}

int main() {
    int n, q;
    cin >> n >> q;
    trains.resize(n);
    rep(i,q) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            trains[x].to = y;
            trains[y].from = x;
        } else if (qi == 2) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            trains[x].to = -1;
            trains[y].from = -1;
        } else {
            int x;
            cin >> x;
            print_train(x-1);
        }
    }
    return 0;
}

