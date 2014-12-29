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

#define Class_Name KingdomAndDucks
#define FuncName minDucks

class Class_Name
{
	public:
	int minDucks(vector <int> t)
	{
		int n[51];
		memset(n, 0, sizeof(n));
		FOR0(i, t.size()){
			n[t[i]]++;
		}
		int mx=0;
		int nt = 0;
		for(int i = 1; i <=50; i++){
			mx = max(mx, n[i]);
			nt += (n[i]!=0);
		}
		return mx*nt;
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
