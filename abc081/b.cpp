#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool canDevide = true;
    int count = 0;
    while(canDevide){
        rep(i,n){
            if(a[i]%2==0) a[i] /= 2;
            else {
                canDevide = false;
                break;
            }
        }
        if(canDevide) count++;
    }
    cout << count << endl;
    return 0;
}