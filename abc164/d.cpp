#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n = 200000;
    vector<int> r(n);
    r.at(0) = 1;
    for(int i = 1; i < n; i++){
        r.at(i) = r.at(i-1) * 10 % 2019;
    }

    // auto dividable = [&](string s){
    //     int residue = 0;
    //     rep(i,s.size()){
    //         int j = s.at(i) - '0';
    //         residue += j * r.at(s.size()-i-1);
    //         residue %= 2019;
    //     }
    //     return residue == 0;
    // };
    string s;
    cin >> s;
    int count = 0;

    for(int i = s.size()-1; 3 <= i; i--){
        int residue = 0;
        for(int j = 0; 0 <= i-j; j++){
            int k = s.at(i-j) - '0';
            residue += k * r.at(j);
            residue %= 2019;
            // cout << i << " " << j << endl;
            // cout << residue << endl;
            if(residue == 0){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}