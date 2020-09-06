#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    int sum = 0;
    rep(i, n) {
        cin >> s.at(i);
        sum += s.at(i);
    }

    if(sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }
    int ans = 0;
    rep(i, n) {
        int p = sum - s.at(i);
        if(p % 10 != 0) ans = max(ans, p);
    }
    cout << ans << endl;
    return 0;
}