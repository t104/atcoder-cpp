#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i, n) cin >> x.at(i);
    
    int sum = 0;
    rep(i, n) {
        int d = min(x.at(i), abs(k - x.at(i)));
        sum += 2*d;
    }
    cout << sum << endl;
    return 0;
}