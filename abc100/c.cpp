#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll power = 0;
    rep(i,n) {
        ll m;
        cin >> m;
        while(m % 2 == 0) {
            power++;
            m /= 2;
        }
    }
    cout << power << endl;
    return 0;
}