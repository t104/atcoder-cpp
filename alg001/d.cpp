#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<bool> exists(n);
    vector<int> a(n);
    rep(i,n){
        exists.at(i) = false;
        int m;
        cin >> m;
        a.at(i) = m-1;
    }
    int x,y;
    x = -1; y = -1;
    rep(i,n){
        if(!exists.at(a.at(i))) exists.at(a.at(i)) = true;
        else{
            y = a.at(i)+1;
        }
    }
    if(y == -1){
        cout << "Correct" << endl;
        return 0;
    }
    rep(i,n) if(!exists.at(i)) x = i+1;
    cout << y << ' ' << x << endl;
    return 0;
}