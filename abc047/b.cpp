#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    int xmin = 0, ymin = 0;
    int xmax = w, ymax = h;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) xmin = max(xmin, x);
        if (a == 2) xmax = min(xmax, x);
        if (a == 3) ymin = max(ymin, y);
        if (a == 4) ymax = min(ymax, y);
    }

    int x = xmax - xmin > 0 ? xmax - xmin : 0;
    int y = ymax - ymin > 0 ? ymax - ymin : 0;
    cout << x * y << endl;
    return 0;
}