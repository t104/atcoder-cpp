#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int m = 1;
    while (m <= n) {
        m *= 2;
    }
    cout << m / 2 << endl;
    return 0;
}