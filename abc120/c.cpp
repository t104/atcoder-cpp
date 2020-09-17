#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    
    int zero = 0, one = 0;
    for (char c : s) {
        if (c == '0') zero++;
        if (c == '1') one++;
    }
    cout << 2 * min(zero, one) << endl;
    return 0;
}