#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int d, g;
int ans = 100100100;


void dfs(int i, int now, int count, vector<int> p, vector<int>& c) {
    if(i == d) {
        if(g <= now) {
            ans = min(ans, count);
        } else {
            for(int j = d-1; 0 <= j; j--) {
            if(g <= now + p.at(j) * (j+1) * 100) {
                int r = (g - now) / ((j+1) * 100);
                if(now + r * (j+1) * 100 < g) r++;
                ans = min(ans, count + r);
                }
            }
        }

        return;
    }

    int next = now;

    dfs(i + 1, next, count, p, c);

    next += p.at(i) * (i + 1) * 100 + c.at(i);
    count += p.at(i);
    p.at(i) = 0;
    dfs(i + 1, next, count, p, c);
}

int main() {
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p.at(i) >> c.at(i);
    dfs(0, 0, 0, p, c);
    cout << ans << endl;
    return 0;
}