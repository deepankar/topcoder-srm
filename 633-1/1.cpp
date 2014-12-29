//pass
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

#define Class_Name Target
#define FuncName draw

class Class_Name
{
	public:
   vector <string> draw(int n)
   {
      char *strc = new char[n+1];
      memset(strc,' ', n);
      strc[n]=0;
      VS a(n, string(strc));
      int cx = (n-1)/2;
      int cy = cx;
      a[cx][cy] = '#';
      for(int i = 2; i <= (n-1)/2; i+=2){//radius
         for(int x = cx-i; x <= cx+i; x++){
            a[x][cy-i] = '#';
            a[x][cy+i] = '#';
         }
         for(int y = cy-i; y <= cy+i; y++){
            a[cx-i][y] = '#';
            a[cx+i][y] = '#';
         }
      }
      delete[] strc;
      return a;
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
		VS r =  g.FuncName(n);
      FOR0(i, r.size()){
         cout << r[i] << "\n";
      }
      cout <<"\n";
	}
	return 0;
}
