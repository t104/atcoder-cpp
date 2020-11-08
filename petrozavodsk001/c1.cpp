/**
 *    author:  tourist
 *    created: 03.02.2018 17:21:41       
**/
#include <bits/stdc++.h>

using namespace std;

string query(int x) {
  cout << x << endl;
  fflush(stdout);
  string res;
  cin >> res;
  if (res == "Vacant") {
    exit(0);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int i = 0;
  int j = n - 1;
  string x = query(0);
  string y = query(n - 1);
  while (true) {
    int k = (i + j) >> 1;
    string z = query(k);
    if ((z == x) != (i % 2 == k % 2)) {
      j = k;
      y = z;
    } else {
      i = k;
      x = z;
    }
  }
  return 0;
}
