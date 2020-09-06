#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    int a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int sum = 0;
        int j = i;
        while(j > 0) {
            sum += j % 10;
            j /= 10;
        }
        if(a <= sum && sum <= b) ans += i;
    }
    cout << ans << endl;
    return 0;
}