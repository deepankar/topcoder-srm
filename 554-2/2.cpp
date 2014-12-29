//passed #permutations #factorial
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

#define Class_Name TheBrickTowerMediumDivTwo
#define FuncName find

class Class_Name
{
   VI heights;
   VI best;
   int mind;
   
   int distance (const VI& seq)
   {
      int d=0;
      if(!seq.size()){
         return 0;
      }
      FOR0(i, seq.size()-1){
         d += std::max(heights[seq[i]], heights[seq[i+1]]);
      }
      return d;
   }

   bool lower(const VI &v1, const VI &v2)
   {
      //assert(v1.size() == v2.size());
      FOR0(i, v1.size()){
         if(v1[i] < v2[i]){
            return true;
         }else if(v2[i] < v1[i]){
            return false;
         }
      }
      return false;  //equal is not lower
   }

   void visit(const vector<int> &stk)
   {
      int d = distance(stk);
      if(d < mind){
         mind = d;
         best = stk;
      }else if(d == mind){
         if(lower(stk, best)){
            best = stk;
         }
      }
      //cout<<d<<" - "; pvInt(stk);
   }
   void rec(const vector<int> &opts, const vector<int> &stk)
   {
      //assert(opts.size() != 0);
      if(opts.size() == 1){
         vector<int> _stk(stk);
         _stk.push_back(opts[0]);
         visit(_stk);
         return;
      }
      FOR0(i, opts.size()){
         vector<int> _opts(opts);
         vector<int> _stk(stk);
         _stk.push_back(opts[i]);
         _opts.erase(i+_opts.begin());
         rec(_opts, _stk);
      }
   }

	public:
   vector <int> find(vector <int> heights)
   {
      this->heights = heights;
      best.clear();
      mind=INT_MAX;
      vector<int> v(heights.size());
      FOR0(i, v.size()){
         v[i] = i;
      }
      rec(v, vector<int>());
      return best;
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
	while((a = parseVI(),a.size()) != 0){
		pv(g.FuncName(a));
	}
	return 0;
}
