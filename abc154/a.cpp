#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string red, blue, discard;
    int a,b;
    cin >> red >> blue;
    cin >> a >> b;
    cin >> discard;
    if(discard == red) a--;
    else b--;
    cout << a << ' ' << b << endl;
    return 0;
}