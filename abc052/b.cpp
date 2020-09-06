#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, x = 0;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(char c : s) {
        if(c == 'I') {
            x++;
        }
        if(c == 'D') {
            x--;
        }
        ans = max(ans, x);
    }

    cout << ans << endl;
    return 0;
}