#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int j = -1;
    rep(i, 5) {
        int n;
        cin >> n;
        if(n == 0) j = i;
    }
    cout << j+1 << endl;
    return 0;
}