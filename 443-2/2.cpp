//passed
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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name CirclesCountry
#define FuncName leastBorders

class Circle
{
   public:
      int x, y, r;
      Circle *parent;
      Circle(int x, int y, int r) : x(x), y(y), r(r), parent(NULL) {}
      bool operator<(const Circle &c) const
      {
         return r < c.r;
      }
      bool IsContainedIn(const Circle &c)
      {
         unsigned int d2 = (x-c.x)*(x-c.x) + (y-c.y)*(y-c.y);
         unsigned int rsum2 = (r+c.r)*(r+c.r);
         return d2 < rsum2 && r < c.r;
      }
      bool Contains(int px, int py)
      {
         unsigned int d2 = (x-px)*(x-px) + (y-py)*(y-py);
         return d2 < r*r;
      }
      int StepsToReach(const Circle *base)
      {
         int n = 0;
         for(Circle *c = this; c; c=c->parent){
            if(c==base){
               return n;
            }
            n++;
         }
         if(base == NULL){
            return n;
         }
         return -1;
      }
};
ostream& operator<<(ostream &os, const Circle &c)
{
   os << "("<<c.x<<","<<c.y<<','<<c.r<<")\n";
   return os;
}

class Class_Name
{
	public:
   int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
   {
      Circle SpaceCircle(-1,-1,-1);
      int nc;
      vector<Circle> c;
      nc = X.size();
      FOR0(i, nc){
         c.push_back(Circle(X[i], Y[i], R[i]));
      }
      sort(c.begin(), c.end());
      FOR0(i, nc){
         Circle &ci = c[i];
         for(int j = i+1; j<nc;j++){
            if(ci.IsContainedIn(c[j])){
               ci.parent = &c[j];
               break;
            }
         }
      }
      Circle *cp1=NULL, *cp2=NULL;
      for(int i = 0; i < nc && (!cp1 || !cp2); i++){
         if(!cp1 && c[i].Contains(x1, y1)){
            cp1 = &c[i];
         }
         if(!cp2 && c[i].Contains(x2, y2)){
            cp2 = &c[i];
         }
      }
      Circle *base = NULL;
      //cout << "point 1 in " << (cp1?*cp1:SpaceCircle) << endl;
      //cout << "point 2 in " << (cp2?*cp2:SpaceCircle) << endl;
      for(Circle *ci = cp1; ci; ci=ci->parent){
         bool done = false;
         for(Circle *cj = cp2; cj; cj=cj->parent){
            if(ci == cj){
               base=ci;
               done = true;
               break;
            }
         }
         if(done)
            break;
      }
      //if(base)
      //   cout <<*base<<endl;
      int n1=0, n2=0;
      n1 = cp1? cp1->StepsToReach(base) : 0;
      n2 = cp2? cp2->StepsToReach(base) : 0;
      //cout << n1<<"+" << n2<<endl;
      return n1+n2;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI x, y, r;
	int x1,y1,x2,y2;
	while((x=parseVI(),x.size()) != 0){
		y= parseVI();
		r= parseVI();
      x1=parseInt();
      y1=parseInt();
      x2=parseInt();
      y2=parseInt();
		cout << g.FuncName(x,y,r,x1,y1,x2,y2) << "\n";
	}
	return 0;
}
