#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = INF;
    int c = 0;
    for(int i = 1; i < n; i++){
        if(s.at(i) == 'E') c++;
    }
    ans = min(ans, c);
    for(int i = 1; i < n; i++){
        if(s.at(i) == 'E') c--;
        if(s.at(i-1) == 'W') c++;
        ans = min(ans, c);
    }
    cout << ans << endl;
    return 0;
}