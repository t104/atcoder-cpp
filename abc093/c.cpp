#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<int> a(3);
    rep(i, 3) cin >> a.at(i);
    int ans = 0;
    sort(a.begin(), a.end());
    while (a.at(0) != a.at(2)) {
        if (a.at(2) - a.at(0) >= 2) {
            a.at(0) += 2;
        }
        else {
            a.at(0)++;
            a.at(1)++;
        }
        sort(a.begin(), a.end());
        ans++;
    }
    cout << ans << endl;
    return 0;
}