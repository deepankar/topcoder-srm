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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name TheMatrix
#define FuncName MaxArea

class Class_Name
{
   bool pos[100][100][100][100];
   int mx;

   void setpos(int x1, int y1, int x2, int y2, bool p){
      pos[x1][y1][x2][y2] = p;
      if(p){
         mx = std::max(mx, (x2-x1+1)*(y2-y1+1));
      }
   }
   bool cxor(char a, char b)
   {
      bool ba = a-'0';
      bool bb = b-'0';
      return ba ^ bb;
   }
	public:
   int MaxArea(vector <string> b)
   {
      mx = 0;
      int nx = b[0].size();
      int ny = b.size();
      FOR0(x1, nx){
         FOR0(y1, ny){
            setpos(x1,y1,x1,y1, true);
            for(int y2 = y1+1; y2 < ny; y2++){
               bool p = pos[x1][y1][x1][y2-1]? cxor(b[y2-1][x1], b[y2][x1]) : false;
               setpos(x1,y1,x1,y2, p);
            }
            for(int x2=1+x1; x2 < nx; x2++){
               bool p = pos[x1][y1][x2-1][y1]? cxor(b[y1][x2-1], b[y1][x2]) : false;
               setpos(x1,y1,x2,y1, p);
               for(int y2 = 1+y1; y2 < ny; y2++){
                  if(pos[x1][y1][x2][y2-1] && pos[x1][y1][x2-1][y2] 
                     && cxor(b[y2-1][x2], b[y2][x2]) && cxor(b[y2][x2-1], b[y2][x2])){
                        setpos(x1,y1,x2,y2, true);
                  }else{
                        setpos(x1,y1,x2,y2, false);
                  }
               }
            }
         }
      }
      return mx;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name *g = new Class_Name();
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VS a;
	while((a = parseVS(), a.size()) != 0){
		cout << g->FuncName(a) << "\n";
	}
	return 0;
}
