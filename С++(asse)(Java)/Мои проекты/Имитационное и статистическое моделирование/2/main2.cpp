#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
const int N = 1000;
using namespace std;
 
long long int calculateCombination(int k, int n) {
	const int a=n;
   long long int **arr= new long long int*[n+1];
   for(int i=0;i<n+1;i++)
	   arr[i] = new long long int[n+1];
 
   for (int i = 0; i <= n; i++) {
      arr[i][0] = 1;
      arr[i][i] = 1;
 
      for (int j = 1; j < i; j++)
         arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
   }
 
   return abs(arr[n][k]);
}
 
long long int calculateFactorial(int k) {
   long long result = 1;
 
   for (int i = 2; i <= k; i++)
      result *= i;
 
   return result;
}
 
 
vector<int> bernoulliDistribution(double p, vector<int> berdist,double *mo, double *disp,double *omo, double *odisp) {
   ofstream ber("Bernoulli distribution.txt");
 
   srand(time(NULL));
   for (int i = 0; i < N; i++) {
      double r = 0.1*(rand()%10);
      if (r < p)
         berdist[i] = 1;
      else
         berdist[i] = 0;
 
      ber << berdist[i] << endl;
   }
   (*mo)=p;
   (*omo)=0;
   *odisp=0;
   for (int i = 0; i < N; i++)
   {
	   (*omo)+=berdist[i];
   }
   *omo=*omo/N;
   for (int i = 0; i < N; i++)
   {
	   (*odisp)+=(berdist[i]-(*omo))*(berdist[i]-(*omo));
   }
   (*odisp)=(*odisp)/N;
   (*disp)=(*mo)*(1-p);
   ber.close();
 
   return berdist;
}
 

// Распределение Пуассона
 

vector<int> poissonDistribution(double mu, vector<int> poidist,double *mo, double *disp,double *omo, double *odisp)
{
   srand(time(NULL));
 
   ofstream poi("Poisson distribution.txt");
 
   for (int i = 0; i < N; i++)
   {
      int x = 0;
      double p = exp(-mu), r = 0.1*(rand()%10);
 
      r -= p;
 
      while (r > 0)
      {
         x++;
         p *= mu / x;
         r -= p;
      }
 
      poidist[i] = x;
 
      poi << poidist[i] << endl;

   }
   *mo=mu;
   *disp=mu;
   (*omo)=0;
   *odisp=0;
   for (int i = 0; i < N; i++)
   {
	   (*omo)+=poidist[i];
   }
   *omo=*omo/N;
   for (int i = 0; i < N; i++)
   {
	   (*odisp)+=(poidist[i]-(*omo))*(poidist[i]-(*omo));
   }
   (*odisp)=(*odisp)/N;
 
   poi.close();
 
   return poidist;
}
 
 
int main()
{
   int n, m;
   double p, mu,mo,disp,omo,odisp;
   vector<int> berdist(N, 0), poidist(N, 0);
 
   // Распределение Бернулли
 
   cout << "Bernoulli distribution" << endl << endl << "Please enter the bernoulli distribution parameter p (0 <= p <= 1)" << endl;
   cin >> p;
   
   berdist = bernoulliDistribution(p, berdist,&mo,&disp,&omo,&odisp);
   cout << "Bernoulli distribution realization in file \"Bernoulli distribution.txt\""<< endl;
   cout << "Dispertion: "<<disp<< "   Otsenka Dispertion: " <<odisp<< "   Matematik Ozidanie: " <<mo<< "   Otsenka Matematik Ozidanie: " <<omo<< "   Oshibka Dispertion: " <<abs(disp-odisp)<<
	    "   Oshibka Matematik Ozidanie: " <<abs(mo-omo);
 
   // Распределение Пуассона
 
   cout << endl;
   cout << "Poisson distribution" << endl << endl << "Please enter the poisson distribution parameter lambda" << endl;
   cin >> mu;
   poidist = poissonDistribution(mu, poidist,&mo,&disp,&omo,&odisp);
   cout << "Poisson distribution realization in file \"Poisson distribution.txt\""<< endl;
   cout << "Dispertion: "<<disp<< "   Otsenka Dispertion: " <<odisp<< "   Matematik Ozidanie: " <<mo<< "   Otsenka Matematik Ozidanie: " <<omo<< "   Oshibka Dispertion: " <<abs(disp-odisp)<<
	    "   Oshibka Matematik Ozidanie: " <<abs(mo-omo)<< endl;
   system("pause");
   return 0;
}
