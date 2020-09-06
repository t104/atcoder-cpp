#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> count(n+1);
    for (int x = 1; x*x < n; x++) {
        for (int y = 1; y*y < n; y++) {
            for (int z = 1; z*z < n; z++) {
                int sum = x*x + y*y + z*z + x*y + y*z + z*x;
                if (n < sum) break;
                count.at(sum)++;
            }
        } 
    }
    for (int i = 1; i <= n; ++i) {
        cout << count.at(i) << endl;
    }
    return 0;
}