#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> vt(N);
    rep(i, N) cin >> vt.at(i);
    int sum = 0;
    for(auto i : vt) sum += i;
    if(H <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}