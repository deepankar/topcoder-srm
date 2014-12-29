// sed 's/[ \t{}",]*//g' in.txt
#pragma once
#include <assert.h>
#include <sstream>

FILE *f;

const char *filename = "in.txt";

void openfile()
{
	if(!f){
		f = fopen(filename, "r");
		if(!f){
			std::cerr << "Unable to open " << filename << "\n";
			exit(1);
		}
	}
}

long long int parseLL()
{
	long long int res = -1;
	openfile();
	char *s = NULL;
	size_t size;
	while(getline(&s, &size, f) != -1){
		int slen = strlen(s);
		if(s[slen - 1] == '\n'){
			s[slen - 1] = 0;
			slen--;
		}
		if(slen == 0){
			free(s);
			s = NULL;
			continue;
		}
		res = atoll(s);
		free(s);
		s = NULL;
		break;
	}
	return res;
}

int parseInt()
{
   return parseLL();
}

VI parseVI()
{
	VI v;
	openfile();
	char *s = NULL;
	size_t size;
	while(getline(&s, &size, f) != -1){
		int slen = strlen(s);
		if(s[slen - 1] == '\n'){
			s[slen - 1] = 0;
			slen--;
		}
		if(slen == 0){
			free(s);
			s = NULL;
			continue;
		}
		const char *tok = strtok(s,"{}, \t");
		while(tok){
			v.push_back(atoi(tok));
			tok = strtok(NULL,"{}, \t");
		}
		free(s);
		s = NULL;
		break;
	}
	return v;
}

template <class T>
vector<T> parseV()
{
	vector<T> v;
	openfile();
	char *s = NULL;
	size_t size;
	while(getline(&s, &size, f) != -1){
		int slen = strlen(s);
		if(s[slen - 1] == '\n'){
			s[slen - 1] = 0;
			slen--;
		}
		if(slen == 0){
			free(s);
			s = NULL;
			continue;
		}
		const char *tok = strtok(s,"{}, \t");
		while(tok){
         istringstream ss(tok);
         T x;
         ss >> x;
			v.push_back(x);
			tok = strtok(NULL,"{}, \t");
		}
		free(s);
		s = NULL;
		break;
	}
	return v;
}

vector<string> parseVS()
{
	vector<string> vec;
	openfile();
	char *s = NULL;
	size_t size;
	bool start = false;
	while(getline(&s, &size, f) != -1){
		int slen = strlen(s);
		if(s[slen - 1] == '\n'){
			s[slen - 1] = 0;
			slen--;
		}
		if(slen == 0){
			if(!start){
				free(s);
				s = NULL;
				continue;
			}else{
				free(s);
				break;
			}
		}
		start = true;
		vec.push_back(string(s));
		free(s);
		s = NULL;
	}
	return vec;
}

/*
void pvpi(VPI v){
	int i;
	cout << "{";
	for(i =0; i < v.size()-1; i++){
		cout << "("<<v[i].first << "," << v[i].second << "), ";
	}
	cout << "("<<v[i].first << "," << v[i].second << ")}\n";
}*/

template<class T>
void pv(const vector<T> &v){
   if(!v.size()){
      cout <<"{}\n";
      return;
   }
	cout << "{";
	FOR0(i,v.size()-1){
		cout << v[i] <<", ";
	}
	cout << v[v.size()-1] << "}\n";
}

template<class T>
ostream& operator<<(ostream &os, const set<T> &s)
{
   os<<"{";
   for(typename set<T>::const_iterator it = s.begin(); it != s.end(); it++){
      os << *it << " ";
   }
   os <<"}";
   return os;
}

template<class K, class T>
void printmap(const map<K,T> &m)
{
   for(typename map<K,T>::const_iterator it = m.begin(); it != m.end(); it++){
      cout << it->first << "->" << it->second << endl;
   }
}

template<class T>
void pvInt(const vector<T> &v){
	cout << "{";
	FOR0(i,v.size()-1){
		cout << (int)v[i] <<", ";
	}
	cout << (int)v[v.size()-1] << "}\n";
}
