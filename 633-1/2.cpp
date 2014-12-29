//pass
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

#define epsilon 0.00001

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name Jumping
#define FuncName ableToGet

class Class_Name
{
	public:
   string ableToGet(int x, int y, vector <int> l)
   {
      double l1 = sqrt(x*x+y*y);
      double s = l1;
      FOR0(i, l.size()){
         s+= l[i];
      }
      s = s/2;
      if(l1 - s > epsilon){
         return "Not able";
      }
      FOR0(i, l.size()){
         if(l[i] -s > epsilon){
            return "Not able";
         }
      }
      return "Able";
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
	int n;
	while((n = parseInt()) != -1){
      int y = parseInt();
		a = parseVI();
		cout << g.FuncName(n,y, a) << "\n";
	}
	return 0;
}
