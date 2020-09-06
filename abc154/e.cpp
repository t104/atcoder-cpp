#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string n;
    int k;
    ll ans = 0;
    cin >> n >> k;
    int size = n.size();
    vector<int> vt(size);
    rep(i,size) {
        vt.at(i) = n.at(i) - '0';
    }
    if(k==1){
        ans += 9*(size-1);
        ans += vt.at(0);
    } else if(k==2) {
        if(size>=3) {
            ans += size *(size-1) *9 *9 /2;
            ans += 9 *(size-2);
        }
        ans += vt.at(1); 
    }
    cout << ans << endl;
    return 0;
}