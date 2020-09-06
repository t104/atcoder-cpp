#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = stoi(s);
    int sum = 0;
    for(char c : s){
        sum += c - '0';
    }
    if(n%sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}