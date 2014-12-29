#include <assert.h>
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

#define Class_Name PathGameDiv2
#define FuncName calc

class Class_Name
{
   int path (const VS &b, int st)
   {
      int l = 0;
      int r = st;
      int i = 0;
      while(i < b[0].size()){
         if(b[r][i] == '.'){
            i++;
         }else{
            assert(b[1-r][i] == '.');
            r = 1-r;
         }
         l++;
      }
      return l;
   }
   int countw(const VS&b)
   {
      int w = 0;
      FOR0(i, b[0].size()){
         w += b[0][i] == '.';
         w += b[1][i] == '.';
      }
      return w;
   }
	public:
   int calc(vector <string> b)
   {
      int l1 = path(b, 0);
      int l2 = path(b, 1);
      int l = std::min(l1, l2);
      int w = countw(b);
      return w - l;
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
//	while((n = parseInt()) != -1){
//		a = parseVI();
   VS b;
   b.push_back(argv[1]);
   b.push_back(argv[2]);
		cout << g.FuncName(b) << "\n";
//	}
	return 0;
}
