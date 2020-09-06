#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string a,b,c;
    cin >> a >> b >> c;
    if(a.at(a.size()-1) == b.at(0) && b.at(b.size()-1) == c.at(0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}