#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<int,int> PI;
typedef vector<PI> VPI;
typedef long long int lint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name TheKingsFactorization
#define FuncName getVector
class Class_Name
{
   class Prime
   {
      public:
         long long prime;
         int power;
         Prime(long long int p, int pwr) : prime(p), power(pwr) {}
   };

   vector<Prime> factorize(long long n)
   {
      long long r = n;
      vector<Prime> res;
      long long sqrtn = sqrtl(n);
      for(long long int p = 2; p <= sqrtn; p++){
         int c = 0;
         while ( r % p == 0){
            c++;
            r = r / p;
         }
         if(c){
            res.push_back(Prime(p, c));
         }
         if(r == 1){
            break;
         }
      }
      if(r > 1){
         res.push_back(Prime(r,1));
      }
      return res;
   }
	public:
   vector<long long> getVector(long long N, vector<long long> p)
   {
      FOR0(i, p.size()){
         N = N/p[i];
      }
      vector<Prime> rp = factorize(N);
      FOR0(i, rp.size()){
         FOR0(j, rp[i].power){
            p.push_back(rp[i].prime);
         }
      }
      sort(p.begin(), p.end());
      return p;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
#if 1
	VLL a;
	lint n;
	while((n = parseLL()) != -1){
		a = parseV<lint>();
		pv( g.FuncName(n, a));
	}
#else
	VI a;
	int n;
	while((a = parseVI(),a.size()) != 0){
		n = parseInt();
		cout << g.FuncName(a,n) << "\n";
	}
#endif
	return 0;
}
