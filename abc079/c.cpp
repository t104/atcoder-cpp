#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

string s;
vector<string> is7;

void dfs(int now, queue<int> que, string op) {
    if(que.empty()) {
        if(now == 7) is7.push_back(op);
        return;
    }
    
    int n = que.front(); que.pop();
    dfs(now + n, que, op + "+");
    dfs(now - n, que, op + "-");
}

int main() {
    cin >> s;
    queue<int> que;
    rep(i, s.size()) que.push(s.at(i) - '0');
    int n = que.front(); que.pop();
    dfs(n, que, "");
    string ans = "";
    rep(i, s.size()) {
        ans += s.at(i);
        if(i < 3) {
            ans += is7.at(0).at(i);
        }
    }
    ans += "=7";
    cout << ans << endl;
    return 0;
}