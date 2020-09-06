#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x, a, b;
    cin >> x;
    for(int i = -119; i < 121; i++) {
        for(int j = -119; j < 121; j++) {
            if(pow(i, 5) - pow(j, 5) == x) {
                a = i;
                b = j;
                break;
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}