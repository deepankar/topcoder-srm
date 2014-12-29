//passed
#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name TheBrickTowerEasyDivTwo
#define FuncName find

class Class_Name
{
	public:
   int find(int rc, int rh, int bc, int bh)
   {
      vector<bool> v(1+rc*rh+bc*bh, false);
      int h[2];
      h[0] = rh;
      h[1] = bh;
      int c[2];
      c[0] = rc;
      c[1] = bc;
      int nxt = 0;
      int ht = 0;
      while(c[nxt]){
         ht += h[nxt];
         c[nxt]--;
         v[ht] = true;
         nxt = 1 - nxt;
      }
      c[0] = rc;
      c[1] = bc;
      nxt = 1;
      ht = 0;
      while(c[nxt]){
         ht += h[nxt];
         c[nxt]--;
         v[ht] = true;
         nxt = 1 - nxt;
      }

      int cnt = 0;
      for(int i = 1; i < v.size(); i++){
         cnt += v[i];
      }
      return cnt;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI a;
	int i,j,k,l;
	while((i = parseInt()) != -1){
		j = parseInt();
		k = parseInt();
		l = parseInt();
		cout << g.FuncName(i,j,k,l) << "\n";
	}
	return 0;
}
