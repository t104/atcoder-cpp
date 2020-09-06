#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i, n-1) cin >> b.at(i);

    int ans = b.at(0);
    for(int i = 0; i < n-2; i++) {
        ans += min(b.at(i), b.at(i+1));
    }

    ans += b.at(n-2);
    cout << ans << endl;
    return 0;
}