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

#define Class_Name AliceGameEasy
#define FuncName findMinimumValue

class Class_Name
{
	public:
   long long findMinimumValue(long long x, long long y)
   {
      long long p = 2*(x+y);
      long long n = sqrtl(p);
      if(n*(n+1) != p){
         return -1;
      }
      long long t = 0;
      long long rd = x;
      for(long long i = n; i>0 && rd > 0; i--){
         if(i <= rd){
            rd -= i;
            t++;
         }
      }
      if(rd){
         return -1;
      }
      return t;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	int n;
//	while((n = parseInt()) != -1){
//		a = parseVI();
long long a = atoll(argv[1]);
long long b = atoll(argv[2]);
		cout << g.FuncName(a,b) << "\n";
	return 0;
}
