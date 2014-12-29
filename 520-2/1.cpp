#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define mx(x,y) ((x) > (y) ? (x) : (y))
#define mn(x,y) ((x) < (y) ? (x) : (y))

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

#define Class_Name SRMRoomAssignmentPhase
#define FuncName countCompetitors

class Class_Name
{
	public:
	countCompetitors(vector <int> r, int k)
	{
		int numbig = 0;
		FOR0(i,r.size()){
			if(r[i]>r[0]){
				numbig++;
			}
		}
		return numbig/k;
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
