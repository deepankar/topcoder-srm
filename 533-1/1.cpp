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

#define Class_Name PikachuEasy
#define FuncName check

const char *sy[] = {"pi", "ka", "chu"};
int l[] = {2,2,3};

class Class_Name
{
	public:
	string check(string str)
	{
		const char *s = str.c_str();
		if(!*s){
			return "YES";
		}
		FOR0(i, 3){
			if(strncmp(s, sy[i], l[i]) == 0){
				return check(string(s + l[i]));
			}
		}
		return string("NO");
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
