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

#define Class_Name EllysTSP
#define FuncName getMax

class Class_Name
{
	public:
	int getMax(string pl)
	{
		const char *p = pl.c_str();
		int n = pl.size();
		int v=0, c=0;
		FOR0(i, n){
			if(p[i]=='V'){
				v++;
			}else{
				c++;
			}
		}
		int n1, n2;
		n1 = min(v,c);
		n2 = max(v,c);
		return 2*n1 + (n2>n1);
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
	cout << g.FuncName(argv[1]) << "\n";
	return 0;
}
