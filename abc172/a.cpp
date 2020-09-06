#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a;
    cin >> a;
    int ans = 0;
    ans += a;
    ans += a*a;
    ans += a*a*a;
    cout << ans << endl;
    return 0;
}