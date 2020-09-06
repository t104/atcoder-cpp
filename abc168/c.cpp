#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double d = pow(a, 2) + pow(b, 2);
    double th =  (double)(2 * M_PI * abs((60 * h + m) - 12 * m))/720;
    double ab = 2 * a * b * cos(th);
    d -= ab;
    d = sqrt(d);
    cout << fixed << setprecision(10) << d << endl;
    return 0;
}