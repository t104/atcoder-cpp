#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    int sum = 0;
    rep(i, n) {
        int x = 1;
        sum++;
        while(x + a.at(i) <= d) {
            sum++;
            x += a.at(i);
        }
    }
    cout << sum + x << endl;
    return 0;
}