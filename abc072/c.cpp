#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    map<int, int> mp;
    rep(i, n) {
        for(int j = -1; j <= 1; j++) {
            int k = a.at(i) + j;
            if(mp.count(k)) {
                mp.at(k)++;
            }
            else {
                mp[k] = 1;
            }
        }
    }
    int ans = 0;
    for(P i : mp) {
        ans = max(ans, i.second);
    }
    cout << ans << endl;
    return 0;
}