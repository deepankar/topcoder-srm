//passed
#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef list<int> LI;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name CasketOfStarEasy
#define FuncName maxEnergy

class Class_Name
{
	VI w;
	int maxe;
	void doo(VI &stk)
	{
		int e = 0;
		FOR0(i, stk.size()){
			int s = stk[i];
			e += w[s-1]*w[s+1];
			cout << stk[i] << " ";
		}
		cout << e << endl;
		maxe = max(maxe,e);
	}

	void comb(vector<int> &stk, const VPI &left, int e)
	{
		if(left.size() == 2){
			maxe = max(maxe, e);
		}
		//for(LI::iterator it = left.begin(); it != left.end(); ++it){
		for(int i = 1; i < left.size() - 1 ; i++){
			VPI l(left);
			VPI::iterator it = l.begin();
			advance(it, i);
			l.erase(it);
			int newe = e + left[i-1].second * left[i+1].second;
//			stk.push_back(left[i]);
			comb(stk, l, newe);
//			stk.pop_back();
		}
	}

	public:
	int maxEnergy(vector <int> w)
	{
		this->w = w;
		maxe=0;
		int n = w.size();
		VI stk;
		VPI l;
		for(int i = 0; i < n; i++){
			l.push_back(PI(i, w[i]));
		}
		comb(stk, l, 0);
		return maxe;
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
	while((a = parseVI(),a.size()) != 0){
		cout << g.FuncName(a) << "\n";
	}
	return 0;
}
