#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name ShadowSculpture
#define FuncName  possible

enum {
   OUT,
   FILL,
   EMPTY,
   CC
};

class coord
{
   public:
   unsigned char x,y,z;
   coord(unsigned char x, unsigned char y,unsigned char z) : x(x), y(y), z(z) {}
};

class Box
{
   public:
   unsigned char st[11][11][11];
   Box(){
      memset(st, OUT, sizeof(st));
   }
   bool happy(vector <string> &XY, vector <string> &YZ, vector <string> &ZX, int cc)
   {
      int n = XY.size();
      FOR0(i, n){
         FOR0(j, n){
            if(XY[i][j] == 'Y'){
               bool fnd = false;
               FOR0(k, n){
                  if(st[i][j][k] == cc){
                     fnd = true;
                     break;
                  }
               }
               if(!fnd) return false;
            }
            if(YZ[i][j] == 'Y'){
               bool fnd = false;
               FOR0(k, n){
                  if(st[k][i][j] == cc){
                     fnd = true;
                     break;
                  }
               }
               if(!fnd) return false;
            }
            if(ZX[i][j] == 'Y'){
               bool fnd = false;
               FOR0(k, n){
                  if(st[j][k][i] == cc){
                     fnd = true;
                     break;
                  }
               }
               if(!fnd) return false;
            }
         }
      }
      return true;
   }
};
ostream &operator<<(ostream &os, const Box &b)
{
   char codes[CC] = {'O', 'F', 'E'};
   int n = 100;
   FOR0(k, n){
      if(b.st[0][0][k] == OUT) break;
      os << "z=" << k << endl;
      FOR0(j, n){
         if(b.st[0][j][k] == OUT) break;
         FOR0(i, n){
            if(b.st[i][j][k] == OUT) break;
            if(b.st[i][j][k] < CC){
               cout << codes[b.st[i][j][k]] << ' ';
            }else{
               cout << (int)b.st[i][j][k] << ' ';
            }
         }
         cout << endl;
      }
   }
   return os;
}

class Class_Name
{
   void bfs(Box &box, int x, int y, int z, int cc)
   {
      queue<coord> q;
      q.push(coord(x,y,z));
      box.st[x][y][z] = cc;
      while(!q.empty()){
         coord c = q.front(); q.pop();
         int x = c.x;
         int y = c.y;
         int z = c.z;
         if(x>0){
            if(box.st[x-1][y][z] == FILL){
               box.st[x-1][y][z] = cc;
               q.push(coord(x-1,y,z));
            }
         }
         if(y>0){
            if(box.st[x][y-1][z] == FILL){
               box.st[x][y-1][z] = cc;
               q.push(coord(x,y-1,z));
            }
         }
         if(z>0){
            if(box.st[x][y][z-1] == FILL){
               box.st[x][y][z-1] = cc;
               q.push(coord(x,y,z-1));
            }
         }
         if(box.st[x+1][y][z] == FILL){
            box.st[x+1][y][z] = cc;
            q.push(coord(x+1,y,z));
         }
         if(box.st[x][y+1][z] == FILL){
            box.st[x][y+1][z] = cc;
            q.push(coord(x,y+1,z));
         }
         if(box.st[x][y][z+1] == FILL){
            box.st[x][y][z+1] = cc;
            q.push(coord(x,y,z+1));
         }
      }
   }
template<class T>
void pv(const vector<T> &v){
   if(!v.size()){
      cout <<"{}\n";
      return;
   }
	cout << "{";
	FOR0(i,v.size()-1){
		cout << v[i] <<", ";
	}
	cout << v[v.size()-1] << "}\n";
}
	public:
   string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
   {
      Box box;
      int n = XY.size();
      FOR0(i, n){
         FOR0(j, n){
            FOR0(k, n){
               box.st[i][j][k] = FILL;
            }
         }
      }
      bool empty = true;
      FOR0(i, n){
         FOR0(j, n){
            if(XY[i][j] == 'N'){
               FOR0(k, n){
                  box.st[i][j][k] = EMPTY;
               }
            } else empty = false;
            if(YZ[i][j] == 'N'){
               FOR0(k, n){
                  box.st[k][i][j] = EMPTY;
               }
            } else empty = false;
            if(ZX[i][j] == 'N'){
               FOR0(k, n){
                  box.st[j][k][i] = EMPTY;
               }
            } else empty = false;
         }
      }
     // cout << box;
    //  cout <<"--------\n";
      int nxtcc = CC;
      FOR0(i, n){
         FOR0(j, n){
            FOR0(k, n){
               if(box.st[i][j][k] == FILL){
                  bfs(box, i,j,k, nxtcc++);
                //  cout << box;
                  if(box.happy(XY, YZ, ZX, nxtcc-1)){
                     return "Possible";
                  }
               }
            }
         }
      }
      if(empty) 
      {
         assert (nxtcc == CC);
         return "Possible";
      }
      return "Impossible";
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VS a,b,c;
	while((a = parseVS(), a.size()) >0 ){
		b = parseVS();
		c = parseVS();
		cout << g.FuncName(a,b,c) << "\n";
	}
	return 0;
}
