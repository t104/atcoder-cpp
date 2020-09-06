#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    if(a % k == 0 || b % k == 0 || a/k < b/k) cout << "OK" << endl;
    else cout << "NG" << endl;
    return 0;
}