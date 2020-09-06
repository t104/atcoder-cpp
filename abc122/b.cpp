#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int count = 0;
    int ans = 0;
    for(char c : s) {
        if(c == 'A' || c == 'T' || c == 'G' || c == 'C') {
            count ++;
        } else {
            ans = max(ans, count);
            count = 0;
        }
    }
    ans = max(ans, count);
    cout << ans << endl;
    return 0;
}