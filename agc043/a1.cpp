#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h = 3;
    int w = 3;
    vector<int> route(h+w-2,1);
    for(int i = 0; i < h-1; ++i) route.at(i) = 0;
    do{
        for(int i : route) cout << i;
        cout << endl;
    } while(next_permutation(route.begin(), route.end()));
    return 0;
}