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

#define Class_Name WinterAndMandarins
#define FuncName getNumber

class Class_Name
{
	public:
   int getNumber(vector <int> bags, int k)
   {
      sort(bags.begin(), bags.end());
      int mindiff = bags[bags.size()-1] - bags[0];
      for(int i = 0; i <= bags.size()-k; i++){
         mindiff = std::min(mindiff, bags[i+k-1] - bags[i]);
      }
      return mindiff;
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
		a = parseVI();
		cout << g.FuncName(n, a) << "\n";
	}
	return 0;
}
