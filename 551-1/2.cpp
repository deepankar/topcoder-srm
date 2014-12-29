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

#define Class_Name CuttingBitString
#define FuncName getmin

class Class_Name
{
   char f[50][50][50];
   char b[50][50];
   bool _p5(luint n)
   {
      if(!n){
         return 0;
      }
      while(n % 5 == 0){
         n = n/5;
      }
      return n==1;
   }

   bool p5(luint n, int l, int i, int j)
   {
      n = n >> (l-j-1);
      n = n << (64-(j-i+1));
      if(!(n>>63)){
         return false;
      }
      n = n >> (64 - (j-i+1));
      return _p5(n);
   }

   char F(int i, int j, int k)
   {
      if(k==1){
         return b[i][j];
      }
      if(f[i][j][k] != 2){
         return f[i][j][k];
      }
      bool r = false;
      for(int m = i; m < j; m++){
         if(b[i][m] && F(m+1,j,k-1)){
            //cout <<"break i,m,j,k=" << i <<" " << m<<" " <<j<<" " <<k<<"\n";
            r = true;
            break;
         }
      }
      f[i][j][k] = r;
      return r;
   }

	public:
   int getmin(string s)
   {
      memset(f, 2, sizeof(f));
      memset(b, 0, sizeof(b));
      luint n = 0;
      FOR0(i,s.size()){
         n = n << 1;
         if(s[i]=='1'){
            n|=1;
         }
      }
      int l=s.size();
      //printf("%x\n"
      FOR0(i, l){
         for(int j = i; j <l; j++){
            b[i][j] = p5(n, l, i, j);
         }
      }
#if 0
      FOR0(i, l){
         FOR0(j, l){
            cout << (int)b[i][j] << ' ';
         }
         cout << "\n";
      }
#endif
      for(int d = 0; d <= l; d++){
         if(F(0, l-1, d)){
            return d;
         }
      }
      return -1;
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
	//while((n = parseInt()) != -1){
		a = parseVI();
		cout << g.FuncName(argv[1]) << "\n";
	//}
	return 0;
}
