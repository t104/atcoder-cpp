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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> places(n);
    vector<deque<int>> cyr(m);
    set<int> front;
    rep(i,m) {
        int K;
        cin >> K;
        rep(j,K) {
            int a;
            cin >> a;
            a--;
            cyr[i].push_back(a);
            places[a].push_back(i);
        }
    }
    queue<int> que;
    rep(i,m) {
        que.push(i);
    }
    while (que.size()) {
        int i = que.front(); que.pop();
        int p = cyr[i].front();
        if (front.count(p)) {
            rep(j,2) {
                int k = places[p][j];
                cyr[k].pop_front();
                if (cyr[k].size()) {
                    que.push(k);
                }
            }
        } else {
            front.insert(cyr[i].front());
        }
    }
    bool ok = true;
    rep(i,m) {
        if (0 < cyr[i].size()) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}