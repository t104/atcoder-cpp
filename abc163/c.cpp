#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 1; i < n; i++){
        int j;
        cin >> j;
        a.at(i) = j-1;
    }
    vector<int> buka(n);
    for(int i = 1; i < n; i++) buka.at(a.at(i))++;
    rep(i,n) cout << buka.at(i) << endl;
    return 0;
}