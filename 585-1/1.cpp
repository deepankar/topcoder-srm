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
typedef vector<string> VS;
typedef long long int lint;
typedef unsigned long long int luint;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name TrafficCongestion
#define FuncName theMinCars

class Class_Name
{
   public:
      int theMinCars(int treeHeight)
      {
         int64_t vm2=1;
         int64_t vm1=1;
         int64_t v=vm1;
         int i;
         for(i=2; i <= treeHeight; i++){
            v = (vm1 + 2*vm2) % 1000000007;
            vm2=vm1;
            vm1=v;
         }
         return v;
      }
};
