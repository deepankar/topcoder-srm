#include <vector>
#include <math.h>
using namespace std;

class Prime
{
   public:
      long long prime;
      int power;
      Prime(long long int p, int pwr) : prime(p), power(pwr) {}
};

vector<Prime> factorize(long long n)
{
   long long r = n;
   vector<Prime> res;
   long long sqrtn = sqrtl(n);
   for(long long int p = 2; p <= sqrtn; p++){
      int c = 0;
      while ( r % p == 0){
         c++;
         r = r / p;
      }
      if(c){
         res.push_back(Prime(p, c));
      }
      if(r == 1){
         break;
      }
   }
   if(r > 1){
      res.push_back(Prime(r,1));
   }
   return res;
}

int _gcd(int a, int b)
{
   if (a % b == 0){
      return b;
   }
   return _gcd(b, a % b);
}
int gcd(int a, int b)
{
   int r = _gcd(a,b);
   //      cout << "gcd(" << a << "," << b << ") = " << r << endl;
   return r;
}

bool isPrime(int n){
   vector<Prime> f = factorize(n);
   return f.size() == 1 && f[0].power==1;
}
