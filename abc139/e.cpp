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
vector<stack<int>> a;
bool all_empty() {
    rep(i,n) {
        if (a[i].size()) return false;
    }
    return true;
}

void ng() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i,n) rep(j,n-1) {
        int x;
        cin >> x;
        a[i].push(x-1);
    }

    int ans = 0;
    queue<int> que;
    rep(i,n) que.push(i);
    while (!que.empty()) {
        queue<int> next;
        vector<int> rm;
        while (!que.empty()) {
            int x = que.front(); que.pop();
            int counter = a[x].top();
            if (a[counter].top() == x) {
                rm.push_back(x);
                rm.push_back(counter);
            }
        }
        sort(rm.begin(), rm.end());
        rm.erase(unique(rm.begin(), rm.end()), rm.end());
        for (auto r: rm) {
            a[r].pop();
            if (0 < a[r].size())
                next.push(r);
        }
        ans++;
        swap(que, next);
    }

    rep(i,n) {
        if (a[i].size()) ng();
    }

    cout << ans << endl;

    return 0;
}