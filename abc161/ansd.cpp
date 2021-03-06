#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int k;
    vector<ll> a;
    for(int i = 1; i <= 9; ++i) a.push_back(i);
    while(1){
        if(k <= a.size()){
            cout << a[k-1] << endl;
            return 0;
        }
        vector<ll> old;
        swap(old, a);
        for(ll x : old){
            for(int i = -1; i <= 1; ++i){
                int d = x%10 + i;
                if(d < 0 || d > 9) continue;
                ll nx = x*10 + i;
                a.push_back(nx);
            }
        }
    }
    return 0;
}