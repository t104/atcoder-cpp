#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    vector<int> box(3);
    cin >> box.at(0) >> box.at(1) >> box.at(2) >> n;

    int ans = 0;
    for(int i = 0; box.at(0) * i <= n; i++) {
        int x = n - box.at(0) * i;
        for(int j = 0; j * box.at(1) <= x; j++) {
            int y = x - box.at(1) * j;
            if(y % box.at(2) == 0) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}