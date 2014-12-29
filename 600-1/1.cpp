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

#define Class_Name ORSolitaire
#define FuncName getMinimum

class Class_Name
{
	public:
   int getMinimum(vector <int> n, int goal)
   {
      VI nums(32,INT_MAX);
      FOR0(b,32){
         if(goal & (1<<b)){
            nums[b] = 0;
         }
      }
      FOR0(i, n.size()){
         if((n[i] | goal) != goal){
            continue;
         }
         FOR0(b,32){
            if((goal & (1<<b)) && (n[i] & (1<<b))){
               nums[b]++;
            }
         }
      }
      int m=INT_MAX;
      FOR0(i,nums.size()){
         m = std::min(m, nums[i]);
      }
      return m;
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
	while((a = parseVI(),a.size()) != 0){
		n = parseInt();
		cout << g.FuncName(a, n) << "\n";
	}
	return 0;
}
