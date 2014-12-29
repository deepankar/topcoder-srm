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
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name LCMSet
#define FuncName equal

/*------ Integer factorization to prime */

class Prime
{
   public:
   int prime, power;
   Prime(int p, int pwr) : prime(p), power(pwr) {}
};
#include "../utils.cpp"


ostream& operator<<(ostream &os, const Prime &p)
{
   os << p.prime << "p" << p.power;
   return os;
}

vector<Prime> factorize(int n)
{
   int r = n;
   vector<Prime> res;
   int sqrtn = sqrt(n);
   for(int p = 2; p <= sqrtn; p++){
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
   cout << "n=" << n << " ";
   pv(res);
   return res;
}
/*---- END ----*/

class Class_Name
{
   typedef map<int, set<int> > PrimePowers;

   PrimePowers getPM(const VI &v)
   {
      PrimePowers pm;
      FOR0(i, v.size()){
         vector<Prime> vp = factorize(v[i]);
         FOR0(j, vp.size()){
            pm[vp[j].prime].insert(vp[j].power);
         }
      }
      cout<<"--------------------------------\n";
      //printmap(pm);
      return pm;
   }

	public:
   string equal(vector <int> A, vector <int> B)
   {
      return getPM(A) == getPM(B)? "Equal" : "Not equal";
   }
};

int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI a,b;
	while((a = parseVI(),a.size()) != 0){
		b = parseVI();
		cout << g.FuncName(a,b) << "\n";
	}
	return 0;
}
