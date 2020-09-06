#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string t;
    cin >> t;
    vector<int> sum(t.size());
    int oddsum = 0, evensum = 0;
    for(int i = 0; i < t.size(); ++i) {
        if(i%2 == 0) {
            oddsum += t.at(i) - '0';
            odd.at(i/2) = oddsum;
        }
        else {
            evensum += t.at(i) - '0';
            even.at(i/2) = evensum;
        }
    }
    return 0;
}