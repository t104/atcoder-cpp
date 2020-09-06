#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int ans = (h2 * 60 + m2) - k - (h1 * 60 + m1);
    cout << ans << endl;
    return 0;
}