#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll H;
    cin >> H;
    int n = log2(H) + 1;
    ll ans = exp2(n) - 1;
    cout << ans << endl;
    return 0;
}