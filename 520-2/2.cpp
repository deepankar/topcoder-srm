#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define mx(x,y) ((x) > (y) ? (x) : (y))
#define mn(x,y) ((x) < (y) ? (x) : (y))

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

#define Class_Name SRMCodingPhase
#define FuncName countScore

class Class_Name
{
	int sc(vector <int> p, vector <int> s, VI f, int l)
	{
		int n = p.size();
		int t = 0;
		FOR0(i,p.size()){
			t += s[i];
		}
		if(t - l > 75){
			switch(n){
				case 3:
					{
						VI p1(2);
						VI s1(2);
						VI f1(2);
						int scr1, scr2, scr3;
#define fill(i,j) p1[i] = p[j]; s1[i] = s[j]; f1[i] = f[j];
						fill(0,0); fill(1,1);
						scr1 = sc(p1,s1,f1,l);
						fill(0,1); fill(1,2);
						scr2 = sc(p1,s1,f1,l);
						fill(0,0); fill(1,2);
						scr3 = sc(p1,s1,f1,l);
						scr1 = mx(scr1, scr2);
						return mx(scr1, scr3);
						break;
					}
					case 2:
					{
						VI p1(1);
						VI s1(1);
						VI f1(1);
						int scr1, scr2;
						fill(0,0);
						scr1 = sc(p1,s1,f1,l);
						fill(0,1);
						scr2 = sc(p1,s1,f1,l);
						return mx(scr1, scr2);
						break;
					}
					case 1:
					{
						return 0;
						break;
					}
			}
		}else{
			int score = 0;
			for(int i = n-1; i >=0; i--){
				int used = mn(l, s[i]-1);
				l -= used;
				int time = s[i] - used;
				int myscore = p[i] - f[i]*time;
				cout << "= " << myscore << "\n";
				score += myscore;
			}
			return score;
		}
	}

	public:
	int countScore(vector <int> p, vector <int> s, int l)
	{
		VI f(3);
		f[0] = 2;
		f[1] = 4;
		f[2] = 8;
		return sc(p,s,f,l);
	}
};

#include "../utils.cpp"
int main(int argc, char **argv)
{
	Class_Name g;
	if(argc == 2 && strstr(argv[1],".txt")){
		filename = argv[1];
	}
	VI p,s;
	int l;
	while((p = parseVI(), p.size()) != 0){
		s = parseVI();
		l = parseInt();
		cout << g.FuncName(p,s,l) << "\n";
	}
	return 0;
}
