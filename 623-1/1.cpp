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
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name UniformBoard
#define FuncName getBoard

class Class_Name
{
   VVI a;
   VVI p;
   int F(int x, int y, const VVI &f){
      if(x < 0 || y < 0){
         return 0;
      }
      return f[x][y];
   }
   int FruitInRect(int sx, int sy, int ex, int ey, const VVI &f)
   {
      return F(ex, ey, f) - F(ex, sy-1, f) - F(sx-1, ey, f) + F(sx-1, sy-1, f);
   }
	public:
   Class_Name(): a(20, VI(20)), p(20, VI(20)) {}
   int getBoard(vector <string> b, int K)
   {
      int n = b.size();
      for(int x = 0; x < n; x++){
         for(int y = 0; y < n; y++){
            int app = F(x,y-1, a) + F(x-1,y, a) - F(x-1,y-1, a);
            int pr = F(x,y-1, p) + F(x-1,y, p) - F(x-1,y-1, p);
            if(b[x][y] == 'A'){
               app++;
            }else if(b[x][y] == 'P'){
               pr++;
            }
            a[x][y] = app;
            p[x][y] = pr;
         }
      }
      int numApples = a[n-1][n-1];
      if(numApples == 0) return 0;
      int numSpaces = n*n - numApples - p[n-1][n-1];
      bool move = true;
      if(numSpaces == 0){
         move = false;
      }
      int mxSize = 0;
      FOR0(sx, n){
         FOR0(sy, n){
            for(int ex = sx; ex < n; ex++){
               for(int ey = sy; ey < n; ey++){
                  int tot  = (ex-sx+1)*(ey-sy+1);
                  if(tot > numApples) continue;
                  if(tot <= mxSize) continue;
                  int app = FruitInRect(sx, sy, ex, ey, a);
                  int pr = FruitInRect(sx, sy, ex, ey, p);
                  int empty = tot - app - pr;
                  if(move){
                     int nummoves = 2*pr + empty;
                     if(nummoves <= K){
                        mxSize = tot;
                     }
                  }else{
                     if(app == tot){
                        mxSize = tot;
                     }
                  }
               }
            }
         }
      }
      return mxSize;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
#if 1
	VI a;
	int n;
	while((n = parseInt()) != -1){
		a = parseVI();
	//	cout << g.FuncName(n, a) << "\n";
	}
#else
	VI a;
	int n;
	while((a = parseVI(),a.size()) != 0){
		n = parseInt();
		cout << g.FuncName(a,n) << "\n";
	}
#endif
	return 0;
}
