#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    vector<vector<int>> vt(n,vector<int>(n));
    for(int i = 0; i < n; ++i){
        vt.at(0).at(i) = str.at(i) - '0';
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            vt.at(i).at(j) = abs(vt.at(i-1).at(j+1) - vt.at(i-1).at(j));
        }
    }
    cout << vt.at(n-1).at(0) << endl;
    return 0;
}