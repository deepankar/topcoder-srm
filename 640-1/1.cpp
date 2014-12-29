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
#include <string>
#include <assert.h>
using namespace std;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name ChristmasTreeDecoration
#define FuncName solve

class Class_Name
{
	public:
   int solve(vector <int> c, vector <int> x, vector <int> y)
   {
      int n = c.size();
      VB s(n+1, false);
      s[1] = true;
      int ins = 1;
      int diff = 0;
      while(ins < n){
         int old_ins = ins;
         int diffcoloredge = -1;
         FOR0(e, x.size()){
            bool b1 = s[x[e]];
            bool b2 = s[y[e]];
            if(b1^b2){
               if(c[x[e]-1] != c[y[e]-1]){
                  if(b1){
                     s[y[e]] = true;
                  }else{
                     s[x[e]] = true;
                  }
                  ins++;
                  break;
               }else{
                  diffcoloredge = e;
               }
            }
         }
         if(old_ins == ins){
            assert(diffcoloredge >= 0);
            bool b1 = s[x[diffcoloredge]];
            bool b2 = s[y[diffcoloredge]];
            assert(b1^b2);
            if(b1){
               s[y[diffcoloredge]] = true;
            }else{
               s[x[diffcoloredge]] = true;
            }
            ins++;
            diff++;
         }
      }
      return diff;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI a,b,c;
	while((a = parseVI(), a.size()) != 0){
		b = parseVI();
		c = parseVI();
		cout << g.FuncName(a,b,c) << "\n";
	}
	return 0;
}
