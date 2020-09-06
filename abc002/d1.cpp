#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#define int long long
typedef long long ll;
using namespace std;

ll N, M, x, y, maxp=0;
set<ll> S[12];

void dfs(ll id, vector<ll> v){
    if(id==N){
        int flag=0;
        for(int i=0;i<N-1;i++) if(v[i]) for(int j=i+1;j<N;j++) if(v[j]&&S[i].find(j)==S[i].end()) flag=1;
        if(!flag) {
            int count=0;
            for(int i=0;i<N;i++) count += v[i];
            maxp = max(maxp, count);
        }
        return;
    }
    v[id] = 0;
    dfs(id+1, v);
    v[id] = 1;
    dfs(id+1, v);
}

signed main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        x--;
        y--;
        S[x].insert(y);
        //S[y].insert(x);
    }
    vector<ll> vemp;
    vemp.resize(N);
    dfs(0, vemp);
    cout << maxp << endl;
    return 0;
}
