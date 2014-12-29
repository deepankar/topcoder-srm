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

#define Class_Name ElectronicPetEasy
#define FuncName isDifficult

class Class_Name
{
	public:
   string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
   {
      int a1[1000];
      int a2[1000];
      FOR0(i, t1){
         a1[i] = st1 + p1*i;
      }
      FOR0(i, t2){
         a2[i] = st2 + p2*i;
      }
      FOR0(i, t1){
         FOR0(j, t2){
            if(a1[i] == a2[j]){
               return "Difficult";
            }
         }
      }
      return "Easy";
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
//		cout << g.FuncName(n, a) << "\n";
	}
	return 0;
}
