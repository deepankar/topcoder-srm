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
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name FoxAndGCDLCM
#define FuncName get

#include "../utils.cpp"
class Class_Name
{
	VPI factorize(long long n)
	{
		VPI r;
//		long long sq = sqrt(n);
		for(long long i = 2; i <= n; i++){
			if(n%i == 0){
				n = n/i;
				PI p(i,1);
				while(n%i == 0){
					n = n/i;
					p.second++;
				}
				r.push_back(p);
			}
		}
		pvpi(r);
		return r;
	}

	public:
	long long get(long long g, long long l)
	{
		if(l % g){
			return -1;
		}
		long long n = l/g;
		VPI f = factorize(n);
		VI pows(f.size());
		int nf = f.size();
		FOR0(i, nf){
			pows[i] = pow(f[i].first, f[i].second);
		}
		long long min = n+1;
		for(int i = 0; i < (1<<nf); i++){
			long long n1=1, n2=1;
			for(int b = 0; b<nf; b++){
				int fac = pows[b];
				if(i&(1<<b)){
					n1 *= fac;
				}else{
					n2 *= fac;
				}
			}
			if(min > n1+n2){
				min = n1+n2;
			}
		}
		return min*g;
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
//	while((n = parseInt()) != -1){
//		a = parseVI();
		cout << g.FuncName(atoll(argv[1]), atoll(argv[2])) << "\n";
//	}
	return 0;
}
