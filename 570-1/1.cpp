//passes system test
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

#define Class_Name RobotHerb
#define FuncName getdist

/* 0,0,0 = at origin, pointing towards positive y */
class tr
{
   union{
      long long x;
      long long d;
   };
   union{
      long long y;
      long long p;
   };
   int a;
   public:
   long long GetX() const{
      return x;
   }
   long long GetY() const{
      return y;
   }
   tr(long long k, long long l, int m) : x(k), y(l), a(m % 360) {}

   tr operator+(const tr &rhs)
   {
      switch(a){
         case 0:
         return tr(x + rhs.p, y + rhs.d, a + rhs.a);
         case 90:
         return tr(x + rhs.d, y - rhs.p, a + rhs.a);
         case 180:
         return tr(x - rhs.p, y - rhs.d, a + rhs.a);
         case 270:
         return tr(x - rhs.d, y + rhs.p, a + rhs.a);
         default:
         fprintf(stderr, "wrong angle\n");
      }
   }

   tr operator*(int T)
   {
      if(a == 0){
         return tr(T*d, T*p, 0);
      }else{
         T = T % 4;
         tr ret(0,0,0);
         FOR0(i, T){
            ret = ret + *this;
         }
         return ret;
      }
   }
};


class Class_Name
{
	public:
   long long getdist(int T, vector <int> a)
   {
      tr perrun(0,0,0);
      FOR0(i, a.size()){
         perrun = perrun + tr(a[i], 0, a[i]*90);
      }
      tr ret = perrun * T;
      return ::llabs(ret.GetX()) + ::llabs(ret.GetY());
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
