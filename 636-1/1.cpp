#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name ChocolateDividingEasy
#define FuncName findBest

class Class_Name
{
   short qs[50][50][50][50];
   int quality(const VS &qu, const int *p)
   {
      int q = 0;
      for(int x = p[0]; x <= p[2]; x++){
         for(int y = p[1]; y<=p[3]; y++){
            q +=  qu[y][x]- '0';
         }
      }
      return q;
   }
	public:
   int findBest(vector <string> c)
   {
      int mxmin = -1;
      int n = c[0].size();
      int m = c.size();
      for(int i = 0; i < n; i++){
         for(int j = i; j<n; j++){
            for(int yi=0; yi <m;yi++){
               for(int yj=yi;yj<m; yj++){
                  int arr[4] = {i,yi, j, yj};
                  qs[i][yi][j][yj] = quality(c, arr);
               }
            }
         }
      }
      for(int i = 1; i < n-1; i++){
         for(int j = i+1; j<n; j++){
            for(int yi=1; yi <m-1;yi++){
               for(int yj=yi+1;yj<m; yj++){
                  int p[9][4] = {
                              {0,0,i-1,yi-1},
                              {i,0,j-1,yi-1},
                              {j,0,n-1,yi-1},
                              {0,yi,i-1,yj-1},
                              {i,yi,j-1,yj-1},
                              {j,yi,n-1,yj-1},
                              {0,yj,i-1,m-1},
                              {i,yj,j-1,m-1},
                              {j,yj,n-1,m-1}
                  };
                  int minq = INT_MAX;
                  FOR0(pp, 9){
                     int *s = p[pp];
                     int q = qs[s[0]][s[1]][s[2]][s[3]];
                     minq = min(minq, q);
                  }
                  mxmin = max(mxmin, minq);
               }
            }
         }
      }
      return mxmin;
   }
};

Class_Name g;
#include "../utils.cpp"
int main(int argc, char **argv)
{
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VS a;
	while((a = parseVS(),a.size()) != 0){
		cout << g.FuncName(a) << "\n";
	}
	return 0;
}
