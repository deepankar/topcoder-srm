#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name GreaterGame
#define FuncName  calc

class Class_Name
{
   int findGT(int x, const VI &m, const VI &h)
   {
      int n = h.size();
      for(int i = x+1; i <=2*n; i++){
         if(binary_search(h.begin(), h.end(), i) && find(m.begin(), m.end(), i) == m.end()){
            return i;
         }
      }
      return -2;
   }
   int findGreatest(const VI &m, const VI &h){
      int n = h.size();
      for(int i = n-1; i >= 0; i--){
         if(find(m.begin(), m.end(), h[i]) == m.end()){
            return h[i];
         }
      }
      assert(0);
      return -3;
   }
   double probless(int x, const VI &v)
   {
      int lesser = lower_bound(v.begin(), v.end(), x) - v.begin();
      return (double)lesser/v.size();
   }
	public:
   double calc(VI h, VI opp)
   {
      int n = opp.size();
      VI m(n, -1);
      sort(opp.begin(), opp.end(), std::greater<int>());
      sort(h.begin(), h.end());
      int i = 0;
      for(; i < n && opp[i] != -1; i++){
         m[i] = findGT(opp[i], m, h);
      }
      for(; i<n; i++){
         m[i] = findGreatest(m,h);
      }
      double escore = 0;
      VI hleft;
      for(int i = 1; i <=2*n; i++){
         if(!binary_search(h.begin(), h.end(), i) && find(opp.begin(), opp.end(), i) == opp.end()){
            hleft.push_back(i);
         }
      }
      FOR0(i,n){
         if(opp[i]!=-1){
            if(m[i] > 0){
               escore++;
            }
            continue;
         }
         escore += probless(m[i], hleft);
      }
      return escore;
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
	VI b;
	while((a = parseVI(), a.size()) > 0){
      b = parseVI();
		cout << g.FuncName(a,b) << "\n";
	}
	return 0;
}
