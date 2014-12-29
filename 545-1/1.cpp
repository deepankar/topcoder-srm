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

#define Class_Name ANDEquation
#define FuncName restoreY

class Class_Name
{
	public:
	int restoreY(vector <int> A)
	{
		int n = A.size();
		FOR0(i, n){
			unsigned int a = 0xffffffff;
			FOR0(j, n){
				if(j==i){
					continue;
				}
				a = a & A[j];
			}
			if(a == A[i]){
				return a;
			}
		}
		return -1;
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
