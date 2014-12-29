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

#define Class_Name XorBoardDivTwo
#define FuncName theMax

class Class_Name
{
	public:
   int theMax(vector <string> b)
   {
      int n = b.size();
      int m = b[0].size();
      int n1 = 0;
      FOR0(i, n){
         FOR0(j, m){
            n1 += (b[i][j]=='1');
         }
      }
      int maxdiff=INT_MIN;
      FOR0(i, n){
         FOR0(j, m){
            int diff=0;
            FOR0(r,m){
               if(r==j){
                  continue;
               }
               if(b[i][r]=='0'){
                  diff++;
               }else{
                  diff--;
               }
            }
            FOR0(c,n){
               if(c==i){
                  continue;
               }
               if(b[c][j]=='0'){
                  diff++;
               }else{
                  diff--;
               }
            }
            maxdiff=max(maxdiff,diff);
         }
      }
      return n1+maxdiff;
   }
};

#if 0
#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI a;
	int n;
	while((n = parseInt()) != -1){
		a = parseVI();
		cout << g.FuncName(n, a) << "\n";
	}
	return 0;
}
#endif
