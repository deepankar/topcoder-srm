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

#define Class_Name StrIIRec
#define FuncName recovstr

class Class_Name
{
	int ninv(const string &s)
	{
		int ni=0;
		FOR0(i, s.size()){
			for(int j = i+1; j< s.size(); j++){
				if(s[j]<s[i]){
					ni++;
				}
			}
		}
		return ni;
	}

	bool incInv(char *s, int n)
	{
		for(int i = n-1; i>0; i--){
			if(s[i-1] < s[i]){
				char c = s[i-1];
				s[i-1] = s[i];
				s[i] = c;
				return true;
			}
		}
		return false;
	}

	bool incStr(char *s, int n)
	{
		for(int i = n-1; i>0; i--){
			if(s[i-1] < s[i]){
				if(s[n-1] > s[i-1]){
					char c = s[i-1];
					s[i-1] = s[n-1];
					s[n-1] = c;
				}else{
					for(int j = i; j <= n-1; j++){
						if(s[j]<s[i-1]){
							char c = s[i-1];
							s[i-1] = s[j-1];
							s[j-1] = c;
							break;
						}
					}
				}
				sort(s+i, s+n);
				return true;
			}
		}
		return false;
	}

	public:
	string recovstr(int n, int minInv, string minStr)
	{
		for(char c = 'a'; c < 'a' + n; c++){
			if(minStr.find(c) == string::npos){
				minStr += c;
			}
		}
		int ni = ninv(minStr);
		if(minInv > ni){
			char *s = strdup(minStr.c_str());
			int l = strlen(s);
			while(ni<minInv){
				if(!incStr(s,l)){
					return "";
				}
				ni = ninv(string(s));
				cout << s << " : " << ni << endl;
			}

			/*FOR0(i, minInv-ni){
				cout << s << " : " << ninv(string(s)) << endl;
				if(!incInv(s, l)){
					return "";
				}
			}*/
			return string(s);
		}
		return minStr;
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
	while(1){
		cin >> n;
		int n2;
		cin >> n2;
		string s;
		cin >> s;
		cout << g.FuncName(n, n2, s) << "\n";
	}
	return 0;
}
