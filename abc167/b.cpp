#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int point = 0;
    if (a <= k) {
        point += a;
        k -= a;
    } else {
        point += k;
        cout << point << endl;
        return 0;
    }
    k -= b;
    if (0 < k) {
        point -= k <= c ? k : c;
    }
    cout << point << endl;

    return 0;
}