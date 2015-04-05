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
typedef vector<VI> VVI;
typedef vector<bool> VB;

#define FOR0(i, n) for(int i = 0; i < n; i++)

#define Class_Name Egalitarianism3
#define FuncName maxCities

class Edge{
   public:
   int v;
   int cost;
   Edge(int v, int cost) : v(v), cost(cost) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
class Class_Name
{
   void _dfs(const Graph &g, int st, VVI &dists, int u, VB &disc)
   {
      disc[u] = true;
      for(auto &edge: g[u]){
         if(!disc[edge.v]){
            int v = edge.v;
            dists[st][v] = dists[v][st] = dists[st][u] + edge.cost;
            _dfs(g, st, dists, edge.v, disc);
         }
      }
   }
   void dfs(const Graph &g, int u, VVI &dists)
   {
      int n = g.size();
      VB disc(n, false);
      _dfs(g, u, dists, u, disc);
   }

   bool addIfCompatible(VI &st, int u, int v, const VVI &dists)
   {
      bool has1 = find(st.begin(), st.end(),u) != st.end();
      bool has2 = find(st.begin(), st.end(),v) != st.end();
      if(!has1 && !has2){
         return false;
      }
      if(has1 && has2){
         return true;
      }
      int toAdd = has1? v : u;
      for(int m: st){
         if(dists[m][toAdd] != dists[u][v]){
            return false;
         }
      }
      st.push_back(toAdd);
      return true;
   }
	public:
   int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
   {
      if(n==1) return 1;
      Graph g(n);
      FOR0(i, n-1){
         int u = a[i]-1;
         int v = b[i]-1;
         g[u].emplace_back(v, len[i]);
         g[v].emplace_back(u, len[i]);
      }
      VVI dists(n, VI(n,0));
      FOR0(u, n){
         dfs(g, u, dists);
      }
      VVI sets; VI setDists;
      FOR0(u, n){
         for(int v = u+1; v < n; v++){
            bool added = false;
            FOR0(i, setDists.size()){
               int sd = setDists[i];
               if(sd == dists[u][v]){
                  VI &st = sets[i];
                  added = addIfCompatible(st, u, v, dists);
               }
            }
            if(!added){
               sets.push_back(VI({u,v}));
               setDists.push_back(dists[u][v]);
            }
         }
      }
      int maxd=0;
      for(auto &s : sets){
         maxd = max(maxd, int(s.size()));
      }
      return maxd;
   }
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
#if 1
	VI a,b,l;
	while((a = parseVI(),b=parseVI(),l=parseVI(),l.size()) > 0){
		cout << g.FuncName(a.size()+1,a,b,l) << "\n";
	}
#else
	VI a;
	int n;
	while((a = parseVI(),a.size()) != 0){
		n = parseInt();
		cout << g.FuncName(a,n) << "\n";
	}
#endif
	return 0;
}
