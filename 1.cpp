#include <iostream>
#include <stdlib.h>

#include <vector>
#include <algorithm>
using namespace std;

class Zoo
{
	public:
	long long theCount(vector<int> answers)
	{
		vector<int>::iterator it;
		sort(answers.begin(), answers.end());
		int n = answers.size();
		//for(it = answers.begin(); it != answers.end(); it++){
		int i;
		for(i = 0 ; i < n - 1; i+=2){
			if(answers[i] != answers[i+1]){
				break;
			}else if(answers[i] != (i/2)){
				return 0;
			}
		}
		//i is the first n which is not a pair
		//answers[i] should be (i/2) + 1;
		long long combs = 1 << (i/2);
		for(int r = i; r < n; r++){
			if(answers[r] != i/2 + (r - i)){
				return 0;
			}
		}
		if(i != n){
			combs *= 2;
		}
		return combs;
	}
  
};

int main(int argc,  char **argv)
{
	Zoo g;
	int myints[] =
	//{5,8}
	//{0, 1, 2, 3, 4}
	//{0, 0, 0, 0, 0, 0}
	//{1, 0, 2, 0, 1}
	{1, 0, 1}
	;
	vector<int> v(myints, myints + sizeof(myints)/sizeof(int));
	std::cout << g.theCount(v) << endl;
}
