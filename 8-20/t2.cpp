#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#define mx(x,y) ((x) > (y) ? (x) : (y))
#define mn(x,y) ((x) < (y) ? (x) : (y))
#define sizearr(a) sizeof(a)/sizeof(a[0])

#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

#define C(dish, day) costs[day*numDish + dish]

class RotatedClock
{
	string mks(int h, int m)
	{
		if(h == 12 && m == 0){
			h = 0;
		}
		std::stringstream ss;
		if(h<10){
			ss<<"0";
		}
		ss << h << ":";
		if(m<10){
			ss<<"0";
		}
		ss<< m;
		return ss.str();
	}

	public:
	string getEarliest(int hh, int mh)
	{
		for(int h = 0; h < 12; h++){
			for(int f = -1; f <=1; f++){
				int s = 2*(mh-hh)+60*h - 720*f;
				if((s % 11) == 0){
					int m = s/11;
					if(m > 0 &&  m <= 60){
						int th = h + m/60;
						m = m % 60;
						int al = 6*m - mh;
						if((al % 30) == 0){
							return mks(th, m);
						}
					}
				}
			}
		}
		return string("");
	}
};

int main(int argc, char **argv)
{
	RotatedClock g;
	cout << g.getEarliest(atoi(argv[1]), atoi(argv[2])) << "\n";
	return 0;
}

