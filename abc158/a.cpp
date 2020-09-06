#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string stations;
    cin >> stations;
    char station = 's';
    string ans;
    for(char c: stations){
        if(station != 's' && station != c)
        {
            ans = "Yes";
            break;
        };
        station = c;
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}