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

#define Class_Name EllysXors
#define FuncName getXor

class Class_Name
{
	public:
	long long getXor(long long _L, long long _R)
	{
		luint L=_L, R=_R;
		luint r = R;
		int n = 0;
		while(r){
			n++;
			r = r >> 1;
		}
		luint res;
		res = ((R-L+1)/2 + ((R-L+1)&1&L))&1;
		for(int i = 1; i < n; i++){
			luint incompLeading = min(R-L+1,
				(1ULL<<(i)) - ((L<<(64-i))>>(64-i)));
			luint incompEnd = ((R <<(64-i)) >> (64-i)) + 1;
			if(incompEnd >= R-L+1){
				incompEnd = 0;
			}
			if(incompEnd == (1ULL<<i)){
				incompEnd = 0;
			}
			luint n1 = 0;
			if((L & (1ULL<<i)) && incompLeading){
				n1 += incompLeading;
			}
			if((R & (1ULL<<i)) && incompEnd){
				n1 += incompEnd;
			}
			if(n1 & 1){
				res |= 1ULL << i;
			}
		}
		return res;
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
		cout << g.FuncName(atoll(argv[1]), atoll(argv[2])) << "\n";
	return 0;
}
