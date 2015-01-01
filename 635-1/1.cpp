//pass
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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name SimilarRatingGraph
#define FuncName maxLength

class Class_Name
{
   double match(const VI &d, const VI &r, int a, int b)
   {
      int ddi = d[a+1] - d[a];
      int ddj = d[b+1] - d[b];
      int pi=a, i=a+1, pj=b, j=b+1;
      int *p1, *p2;
      double len = 0;
      if(ddi > ddj){
         p1 = &pi;
         p2 = &i;
      }else{
         p1 = &pj;
         p2 = &j;
      }
      while( j < d.size() && 
         (d[j] - d[pj])*ddi == (d[i]-d[pi])*ddj &&
         (r[j] - r[pj])*ddi == (r[i]-r[pi])*ddj){
         long int dx = d[*p2] - d[*p1];
         long dy = r[*p2] - r[*p1];
         len += sqrt(dx*dx + dy*dy);
         pi=i;
         pj=j;
         i++;
         j++;
      }
      return len;
   }
	public:
   double maxLength(vector <int> d, vector <int> r)
   {
      int n = d.size();
      double mx = 0;
      for(int i = 0; i < n-2; i++){
         for(int j = i+1; j <n-1; j++){
            double m = match(d,r,i,j);
            mx = max(mx, m);
         }
      }
      return mx;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
#if 0
	VI a;
	int n;
	while((n = parseInt()) != -1){
		a = parseVI();
	//	cout << g.FuncName(n, a) << "\n";
	}
#else
	VI a,b;
	while((a = parseVI(),a.size()) != 0){
		b = parseVI();
		cout << g.FuncName(a,b) << "\n";
	}
#endif
	return 0;
}
