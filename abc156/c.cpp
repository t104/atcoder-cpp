#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x.at(i);
    
    int minsum = 100100100;

    for(int i = 1; i <= 100; i++) {
        int sum = 0;
        rep(j, n) {
            sum += pow(x.at(j) - i, 2);
        }
        minsum = min(minsum, sum);
    }

    cout << minsum << endl;
    return 0;
}