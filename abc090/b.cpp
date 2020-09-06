#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = a; i <= b; i++) {
        string s = to_string(i);
        string r = s;
        reverse(r.begin(), r.end());
        if(s == r) ans++;
    }

    cout << ans << endl;

    return 0;
}