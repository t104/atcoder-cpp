#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

string s[100005];
int n;
vector<char> ans;
bool ok = false;


void dfs(int i, int a, int b, int c, vector<char> selection) {
    if(i == n) {
        ok = true;
        ans = selection;
        return;
    }
    string action = s[i];

    if(action == "AB") {
        if(0 <= b - 1) {
            selection.at(i) = action.at(0);
            dfs(i + 1, a + 1, b - 1, c, selection);
        }
        if(0 <= a - 1) {
            selection.at(i) = action.at(1);
            dfs(i + 1, a - 1, b + 1, c, selection);
        }
    } else if(action == "AC") {
        if(0 <= c - 1) {
            selection.at(i) = action.at(0);
            dfs(i + 1, a + 1, b, c - 1, selection);
        }
        if(0 <= a - 1) {
            selection.at(i) = action.at(1);
            dfs(i + 1, a - 1, b, c + 1, selection);
        }
    } else if(action == "BC") {
        if (0 <= c - 1) {
            selection.at(i) = action.at(0);
            dfs(i + 1, a, b + 1, c - 1, selection);
        }
        if(0 <= b - 1) {
            selection.at(i) = action.at(1);
            dfs(i + 1, a, b - 1, c + 1, selection);
        }
    }
}

int main() {
    int a, b, c;
    cin >> n >> a >> b >> c;
    rep(i, n) cin >> s[i];
    vector<char> selection(n);
    dfs(0, a, b, c, selection);
    if(ok) {
        cout << "Yes" << endl;
        rep(i, n) cout << ans.at(i) << endl;
    }
    else cout << "No" << endl;
    return 0;
}