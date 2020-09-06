#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll sum = 0;
    sum += (N * (N+1)) /2;
    sum -= (3*(1+N/3)*(N/3))/2;
    sum -= (5*(1+N/5)*(N/5))/2;
    sum += (15*(1+N/15)*(N/15))/2;
    cout << sum << endl;
    return 0;
}