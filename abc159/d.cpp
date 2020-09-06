#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    map<int,int> m;
    cin >> N;
    vector<int> vec(N);
    rep(i, N){
        cin >> vec.at(i);
        m[vec.at(i)]++;
    }
    ll count = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr){
        int n = itr->second;
        count += n*(n-1)/2;
    }

    for(int i : vec){
        cout << count - (m[i]-1) << endl;
    }
    return 0;
}