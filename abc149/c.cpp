#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isPrime(int x) {
    for(int i = 2; i < x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int x;
    cin >> x;

    while(!isPrime(x)) {
        x++;
    }
    cout << x << endl;
    return 0;
}