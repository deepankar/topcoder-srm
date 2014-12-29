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

#define Class_Name KingdomAndTrees
#define FuncName minLevel

class Class_Name
{
	public:
	int minLevel(vector <int> h)
	{
		int x = 0;
		int n = h.size();
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j<n; j++){
				int mx = ceil((h[i]-h[j] +(j-i))/2.0f);
				if(h[i] - mx <= 0){
					mx += (mx - h[i] + 1);
				}
				x = max(x, mx);
			}
		}
		return x;
	}
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI n;
	while((n = parseVI(), n.size()) != 0){
		cout << g.FuncName(n) << "\n";
	}
	return 0;
}
