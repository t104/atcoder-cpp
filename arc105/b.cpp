#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    priority_queue<int> a;
    int m = 1001001001;
    rep(i,n) {
        int ai;
        cin >> ai;
        a.push(ai);
        chmin(m, ai);
    }
    while (m < a.top()) {
        int M = a.top();
        a.pop();
        int next = M % m;
        if (next == 0) continue;
        chmin(m, next);
        a.push(next);
    }
    cout << m << endl;
    return 0;
}