#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define mx(x,y) ((x) > (y) ? (x) : (y))
#define mn(x,y) ((x) < (y) ? (x) : (y))
#define sizearr(a) sizeof(a)/sizeof(a[0])

#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

#define C(dish, day) costs[day*numDish + dish]

class FortunateNumbers
{
	public:
	std::set<int> found;

	bool isfort(int n)
	{
		int d;
		while(n){
			d = n % 10;
			if(d != 5 && d != 8){
				return false;
			}
			n = n / 10;
		}
		return true;
	}

	int getFortunate(vector <int> a, vector <int> b, vector <int> c)
	{
		int ni = a.size();
		int nj = b.size();
		int nk = c.size();
		for(int i = 0; i < ni; i++){
			for(int j = 0; j < nj; j++){
				for(int k = 0; k < nk; k++){
					int s = a[i] + b[j] + c[k];
					if(isfort(s)){
						found.insert(s);
					}
				}
			}
		}
		return found.size();
	}
};

int main(int argc, char **argv)
{
	int aa[] = {};
	int ab[] = {};
	int ac[] = {};
	vector<int> a;
	vector<int> b;
	vector<int> c;
	//vector<string> p(pa, pa + sizearr(pa));
	FortunateNumbers g;
	g.getFortunate(a,b,c);
	return 0;
}

