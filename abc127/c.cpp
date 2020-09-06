#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int maxL =  -1, minR = 1001001001;
    rep(i, m) {
        int l,r;
        cin >> l >> r;
        maxL = max(maxL, l);
        minR = min(minR, r);
    }
    int d = minR - maxL;
    if(d < 0) {
        cout << 0 << endl;
    }
    else {
        cout << d + 1 << endl;
    }
    return 0;
}