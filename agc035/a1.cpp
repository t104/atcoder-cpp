// https://atcoder.jp/contests/agc035/submissions/17180787
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
using P = pair<int, int>;

bool solve(vector<int> a, int n){
    sort(a.begin(), a.end());
    vector<P> backet(1, make_pair(a[0], 1));
    for(int i = 1; i < n; i++){
        if(backet.rbegin()->first == a[i]) backet.rbegin()->second++;
        else backet.push_back(make_pair(a[i], 1)); 
    }
    
    bool ans = true;
    if(backet.size() == 1 && backet[0].first == 0) ans = true;
    else if(n % 3 == 0){
        if(backet.size() == 2 && backet[0].first == 0 &&
        backet[0].second*3 == n) ans = true;
        else if(backet.size() == 3 &&
        ((backet[0].first ^ backet[1].first) ^ backet[2].first) == 0 &&
        backet[0].second * 3 == n && backet[1].second * 3 == n &&
        backet[2].second * 3 == n) ans = true;
        else ans = false;
    }else ans = false;

    return ans;
}

int main(){
    int n;
    
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(solve(a, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
