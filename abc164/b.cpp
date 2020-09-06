#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int aoki = a % d == 0 ? a/d : a/d + 1;
    int takahashi = c % b == 0 ? c/b : c/b + 1;
    if(takahashi <= aoki) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}