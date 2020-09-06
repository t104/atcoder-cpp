#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int d, n;
    cin >> d >> n;
    int div = pow(100, d);
    if(n >= 100) n += n/100;
    int ans = n * div;
    cout << ans << endl;
    return 0;
}