#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int L;
    cin >> L;
    double l = (double) L/3;
    double S = pow(l,3);
    cout << fixed << setprecision(8) << S << endl;
    return 0;
}