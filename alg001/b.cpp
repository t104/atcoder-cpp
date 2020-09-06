#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n-1){
        ll dif = a.at(i+1) -  a.at(i);
        if(dif == 0){
            cout << "stay" << endl;
        } else if(0 < dif){
            cout << "up " << abs(dif) << endl;
        } else {
            cout << "down " << abs(dif) << endl;
        }
    }
    return 0;
}