#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int a, b, c, x;

int main() {
    cin >> a >> b >> c >> x;
    int count = 0;
    rep(i, a+1) rep(j, b+1) rep(k, c+1) {
        int p = 500 * i + 100 * j + 50 * k;
        if(p == x) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}