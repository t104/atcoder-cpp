#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int MAX_N = 100100100;
vector<int> depth(100005, MAX_N);
vector<vector<int>> rt(100005);
int n, m;

void bfs() {
    queue<int> q;
    q.push(0);
    int d = 1;
    
    while(q.size()) {
        int i = q.front(); q.pop();
        auto list = rt.at(i);
        for(int j : list) {
            depth.at(j) = min(depth.at(j), d);
            q.push(j);
        }
        d++;
        if(n < d) break;
    }
    return;
}

int main() {
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        rt.at(a).push_back(b);
        rt.at(b).push_back(a);
    }

    depth.at(0) = 0;
    bfs();
    rep(i, n) {
        if(depth.at(i) == MAX_N) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i < n; i++) {
        int ans = 0;
        for(int j : rt.at(i)) {
            if(depth.at(i) - 1 == depth.at(j)) {
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}