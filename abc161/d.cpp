#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll maxk = LLONG_MAX;



int main() {
    int k;
    cin >> k;
    int count = 0;
    int ans = -1;
    for(ll i = 1; i < maxk; i++){
        bool run = true;
        for(ll div = 1; i/(div*10) > 0; div *= 10){
            if(abs(i/(div*10)%10 - (i/div)%10) > 1){
                run = false;
                i += div;
                i -= i % div;
                break;
            }
        }
        if(run) {
            count++;
            // cout << i << endl;
        }
        if(count == k){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}