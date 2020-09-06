#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >> n >> k;
    vector<double> vt(n);
    double s=0, M=0;
    rep(i,n) {
        int p;
        cin >> p;
        vt.at(i) = (double) (p+1)/2;
    }
    rep(i,k) s += vt.at(i);
    M = s;
    for(int i=0; i<n-k; ++i) {
        s = s - vt.at(i) + vt.at(i+k);
        M = max(M,s);
    }
    // M /= 2;
    cout << fixed << setprecision(10) << M << endl;
    return 0;
}