#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

void printAll(vector<int> &vt) {
    rep(i, vt.size()-1) cout << vt.at(i) << ' ';
    cout <<  vt.at(vt.size()-1) << endl;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(s.size());

    char now = 'R';
    int odd = 0, even = 0;
    int pos = 0;
    rep(i, n) {
        if(now == 'R' && s.at(i) == 'L') {
            pos = i-1;
        }
        if(now == 'L' && s.at(i) == 'R') {
            ans.at(pos) = odd;
            ans.at(pos+1) = even;
            if((pos%2) == 0) {
                swap(ans.at(pos), ans.at(pos+1));
            }
            even = 0; odd = 0;
        }
        now = s.at(i);
        if((i%2) == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    ans.at(pos) = odd;
    ans.at(pos+1) = even;
    if((pos%2) == 0) {
        swap(ans.at(pos), ans.at(pos+1));
    }

    printAll(ans);
    
    return 0;
}