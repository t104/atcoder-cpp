#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string str;
    cin >> str;
    int n = 0;
    int w = 0;
    int s = 0;
    int e = 0;
    for(char c : str){
        if(c == 'N') n = 1;
        if(c == 'W') w = 1;
        if(c == 'S') s = 1;
        if(c == 'E') e = 1;
    }
    if((n+s)%2 == 0 && (w+e)%2 == 0) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}