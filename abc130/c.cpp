#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    cout << fixed << setprecision(10);
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    
    int mult = 0;
    double ans = (double) w * h / 2;
    if (2*x == w && 2*y == h) mult = 1;
    cout << ans << ' ' << mult << endl;
    return 0;
}