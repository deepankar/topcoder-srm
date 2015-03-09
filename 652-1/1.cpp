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
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name ThePermutationGame
#define FuncName findMin
  
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

bool isPrime(int n){
   vector<Prime> f = factorize(n);
   return f.size() == 1 && f[0].power==1;
}


class Class_Name 
{
	public:
   int findMin(int n){
      luint m = 1;
      for(int ni = 1; ni <= n; ni++){
         if(!isPrime(ni)) continue;
         int p;
         luint acc=ni;
         luint lteAcc;
         for(p=1; acc <= n; acc*=ni, p++) {
            lteAcc = acc;
         }
//         cout << "*" << lteAcc << endl;
         m = (m * lteAcc) % 1000000007LLU;
      }
      return m;
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
	VI a;
	int n;
//	while((n = parseInt()) != -1){
   n = atoi(argv[1]);
		cout << g.FuncName(n) << "\n";
//	}
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
