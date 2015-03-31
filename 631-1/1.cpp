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
//typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name TaroJiroGrid
#define FuncName getNumber

class Class_Name
{
   bool good(const VS&g){
      int n = g.size();
      for(int c = 0; c < g.size(); c++){
         char prevchar='x';
         int prevCount=0;
         for(int i = 0; i < n; i++){
            if(g[i][c] == prevchar){
               prevCount++;
               if(prevCount > n/2){
                  return false;
               }
            }else{
               prevCount=1;
               prevchar = g[i][c];
            }
         }
      }
      return true;
   }
	public:
   int getNumber(vector <string> grid)
   {
      if(good(grid)){
         return 0;
      }
      int n = grid.size();
      char colors[]= {'W','B'};
      for(int r = 0; r< n; r++){
         FOR0(colori, 2){
            VS g(grid);
            char color=colors[colori];
            g[r].assign(n,color);
            if(good(g)) return 1;
         }
      }
      return 2;
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
	VS s;
	int n;
	while((s= parseVS(),s.size()) != 0){
		cout << g.FuncName(s) << "\n";
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
