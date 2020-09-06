#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    vector<int> a;
    rep(i,n) cin >> a.at(i);
    vector<int> sum;
    for(int i = 0; i <= 1; i++){
        int s = 0;
        for(int j = i; j < n; j+=2){
            s += a.at(j);
        }
        sum.push_back(s);
    }
            
    return 0;
}