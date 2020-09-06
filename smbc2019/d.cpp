#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(char c = '0'; c <= '9'; c++) {
        size_t posc = s.find(c);
        if(posc == string::npos || n-2 < posc) continue;
        for(char d = '0'; d <= '9'; d++) {
            size_t posd = s.find(d, posc + 1);
            if(posd == string::npos || n-1 < posd) continue;
            for(char e = '0'; e <= '9'; e++) {
                size_t pose = s.find(e, posd + 1);
                if(pose == string::npos) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}