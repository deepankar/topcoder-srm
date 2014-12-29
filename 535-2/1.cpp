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

#define Class_Name FoxAndIntegers
#define FuncName get

class Class_Name
{
	public:
	vector <int> get(int x, int y, int z, int w)
	{
		if(z-x != w+y){
			return VI();
		}
		if(((x+z)&1) ||
			((z-x)&1) ||
			((w+y)&1) ||
			((w-y)&1)){
			return VI();
		}
		VI r(3);
		r[0] = (x+z)/2;
		r[1] = (z-x)/2;
		r[2] = (w-y)/2;
		return r;
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
