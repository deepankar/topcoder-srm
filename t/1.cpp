#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define mx(x,y) ((x) > (y) ? (x) : (y))
#define mn(x,y) ((x) < (y) ? (x) : (y))
#define sizearr(a) sizeof(a)/sizeof(a[0])

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define C(dish, day) costs[day*numDish + dish]

class MysteriousRestaurant
{
	public:
	int maxDays(vector <string> prices, int budget)
	{
		const char *p0 = prices[0].c_str();
		int numDish = strlen(p0);
		int numDays = prices.size();
		char *costs = new char[numDish*numDays];
		for(int d = 0; d < numDays; d++){
			const char *p = prices[d].c_str();
			for(int i = 0; i < numDish; i++){
				if(p[i] <= '9'){
					C(i, d) = p[i] - '0';
				}else if(p[i] <= 'Z'){
					C(i,d) = p[i] -'A' + 10;
				}else if(p[i] <= 'z'){
					C(i,d) = p[i] -'a' + 36;
				}
			}
		}
		int totalCosts[7] = {0};
		int day = 0;
		while(budget > 0){
			int minCost = INT_MAX;
			for(int c = 0; c < numDish; c++){
				int d = day;
				int cost = 0;
				while(d>=0){
					cost += C(c, d);
					d -= 7;
				}
				if(cost < minCost){
					minCost = cost;
				}
			}
			budget -= minCost - totalCosts[day%7];
			totalCosts[day%7] = minCost;
			day++;
		}
		if(budget == 0){
			return day;
		}else{
			return day - 1;
		}
	}
};

int main(int argc, char **argv)
{
	MysteriousRestaurant g;
	string pa[] = 
	{"26", "14", "72", "39", "32", "85", "06"};
	int b = 13;
	vector<string> p(pa, pa + sizearr(pa));
	cout << g.maxDays(p, b) << endl;
	return 0;
}

