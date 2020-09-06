#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, y;
    cin >> n >> y;
    y /= 1000;
    
    rep(i,y) rep(j,y) {
        int k = y - (10 * i + 5 * j);
        if (0 <= k && i+j+k == n) {
            printf("%d %d %d\n", i, j, k);
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}