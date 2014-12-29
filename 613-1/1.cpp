//passed
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

#define Class_Name TaroFriends
#define FuncName getNumber

class CatPair
{
   int cat1, cat2;
   bool dir1, dir2;
   public:
   int left, right;
   CatPair(int c1, int c2, bool d1, bool d2, int l, int r) : cat1(c1), cat2(c2), dir1(d1), dir2(d2), left(l), right(r) {}
   bool operator<(const CatPair &cp) const
   {
      return (right-left) < (cp.right-cp.left);
   }
};

class Class_Name
{
   VI *c;
   int catmove(int cat, bool dir, int x){
      return (*c)[cat] + (dir? 1:-1)*x;
   }
   bool liesin(int c, int l, int r){
      return c>=l && c <=r;
   }
   bool allcatsfit(int l, int r, int x){
 //     cout <<"fits " << l <<"," << r << " ?\n";
      FOR0(cat, c->size()){
         if(!liesin((*c)[cat]-x, l, r) && !liesin((*c)[cat]+x, l, r)){
   //         cout <<"   -no " << (*c)[cat] << endl;
            return false;
         }
      }
      return true;
   }
	public:
   int getNumber(vector <int> c, int x)
   {
      this->c = &c;
      vector<CatPair> catpairs;
      if(c.size() <= 1) return 0;
      int n = c.size();

      FOR0(cat1, n-1){
         for(int cat2=cat1+1; cat2 < n; cat2++){
            FOR0(dir1, 2){
               FOR0(dir2, 2){
                  int pos1 = catmove(cat1,dir1,x);
                  int pos2 = catmove(cat2,dir2,x);
                  catpairs.push_back(CatPair(cat1,cat2,dir1,dir2,min(pos1,pos2), max(pos1,pos2)));
               }
            }
         }
      }
      sort(catpairs.begin(), catpairs.end());
      FOR0(cp, catpairs.size()){
         if(allcatsfit(catpairs[cp].left, catpairs[cp].right, x)){
            return catpairs[cp].right - catpairs[cp].left;
         }
      }
      return INT_MAX;
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
		n = parseInt();
		cout << g.FuncName(a,n) << "\n";
	}
	return 0;
}
