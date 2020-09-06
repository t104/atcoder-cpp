#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x;
    cin >> x;
    int n = 0;
    while (n * (n+1) < 2 * x) {
        ++n;
    }
    cout << n << endl;
    return 0;
}