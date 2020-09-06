#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x, y;
    cin >> x >> y;
    int n = min(x,y);
    int m = max(x,y);
    if (n == 1) {
        if (m == 1) {
            cout << 1 << endl;
            return 0;
        }
        cout << m-2 << endl;
        return 0;
    }
    cout << (ll)(m-2) * (n-2) << endl;
    return 0;
}