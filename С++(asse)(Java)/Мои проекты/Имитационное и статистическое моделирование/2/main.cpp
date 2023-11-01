#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "fun_h.h"
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
 
double calculateXi2ForPearsonTest(int n) {
   double d = 2.0637 * pow(((double)log(20.) - 0.16), 0.4274) - 1.5774; // eps = 0.05
 
   double A = d * sqrt(2.);
   double B = (2.0 / 3) * (pow(d, 2) - 1);
   double C = d * (pow(d, 2) - 7) / (9 * sqrt(2.));
   double D = -(6 * pow(d, 4) + 14 * pow(d, 2) - 32) / 405;
   double E = d * (9 * pow(d, 4) + 256 * pow(d, 2) - 433) / (4860 * sqrt(2.));
 
   return n + A * sqrt((double)n) + B + C / sqrt((double)n) + D / n + E / (n * sqrt((double)n));
}
 
// Распределение Бернулли
 
void pearsonTestForBernulli(double p, vector<int> berdist) {
   vector<int> nCount(2, 0);
 
   double XI_2 = calculateXi2ForPearsonTest(1);
 
   for (int i = 0; i < N; i++)
      ++nCount[berdist[i]];
 
   double xi_2 = pow(nCount[0] - ((1 - p) * N), 2.0) / ((1 - p) * N) + pow(nCount[1] - (p * N), 2.0) / (p * N);
 
   if (xi_2 < XI_2)
      cout << endl << "Pearson test: " << xi_2 << " < " << XI_2 << " => true sequence" << endl;
   else
      cout << endl << "Pearson test: " << xi_2 << " > " << XI_2 << " => false sequence" << endl;
}
 
vector<int> bernoulliDistribution(double p, vector<int> berdist) {
   ofstream ber("Bernoulli distribution.txt");
 
   srand(time(NULL));
   for (int i = 0; i < N; i++) {
      double r = rand();
 
      if (r < p)
         berdist[i] = 1;
      else
         berdist[i] = 0;
 
      ber << berdist[i] << endl;
   }
 
   ber.close();
 
   return berdist;
}
 
// Биномиальное аспределение
 
void pearsonTestForBinomial(int n, double p, vector<int> bindist) {
   vector<int> nCount(N + 1, 0);
   double xi_2 = 0.0, XI_2 = calculateXi2ForPearsonTest(n);
 
   for (int i = 0; i < N; i++)
      ++nCount[bindist[i]];
 
   for (int i = 0; i <= n; i++) {
      double tCount = calculateCombination(i, n) * pow(p, i) * pow(1 - p, n - i) * N;
      xi_2 += pow(nCount[i] - tCount, 2) / tCount;
   }
 
   if (xi_2 < XI_2)
      cout << endl << "Pearson test: " << xi_2 << " < " << XI_2 << " => true sequence" << endl;
   else
      cout << endl << "Pearson test: " << xi_2 << " > " << XI_2 << " => false sequence" << endl;
}
 
vector<int> binomialDistribution(int n, double p, vector<int> bindist) {
   ofstream bin("Binomial distribution.txt");
   double q = 1.0 - p, c = p / q;
 
   srand(time(NULL));
   for (int i = 0; i < N; i++) {
      int x = 0;
      double r = rand();
 
      p = pow(q, n);
      r -= p;
 
      while (r > 0) {
         x++;
         p *= c * (n + 1 - x) / x;
         r -= p;
      }
 
      bindist[i] = x;
 
      bin << bindist[i] << endl;
   }
 
   bin.close();
 
   return bindist;
}
 
// Отрицательное биномиальное распределение
 
void pearsonTestForNegBinomial(int m, double p, vector<int> negbindist) {
   sort(negbindist.begin(), negbindist.end());
 
   int max = negbindist[N - 1];
   vector<int> nCount(max + 1, 0);
   double xi_2 = 0.0, XI_2 = calculateXi2ForPearsonTest(19);
 
   for (int i = 0; i < N; i++)
      ++nCount[negbindist[i]];
 
   for (int i = 0; i <= max; i++) {
      double tCount = calculateCombination(i, i + m - 1) * pow(p, m) * pow(1 - p, i) * N;
      xi_2 += pow(nCount[i] - tCount, 2) / tCount;
   }
 
   if (xi_2 < XI_2)
      cout << endl << "Pearson test: " << xi_2 << " < " << XI_2 << " => true sequence" << endl;
   else
      cout << endl << "Pearson test: " << xi_2 << " > " << XI_2 << " => false sequence" << endl;
}
 
vector<int> negBinomialDistribution(int m, double p, vector<int> negbindist) {
   ofstream negbin("Negative binomial distribution.txt");
   double q = 1.0 - p;
 
   srand(time(NULL));
   for (int i = 0; i < N; i++) {
      int z = 0;
      double r = rand();
      p = pow(1 - q, m);
      r -= p;
 
      while (r > 0) {
         z++;
         p *= q * (m - 1 + z) / z;
         r -= p;
      }
 
      negbindist[i] = z;
 
      negbin << negbindist[i] << endl;
   }
 
   negbin.close();
 
   return negbindist;
}
 
// Геометрическое распределение
 
void pearsonTestForGeometric(double p, vector<int> geodist)
{
   sort(geodist.begin(), geodist.end());
 
   int max = geodist[N - 1];
 
   vector<int> nCount(max + 1, 0);
 
   double xi_2 = 0.0, XI_2 = calculateXi2ForPearsonTest(max);
 
   for (int i = 0; i < N; i++)
      ++nCount[geodist[i]];
 
   for (int i = 0; i <= max; i++)
   {
      double tCount = pow(1 - p, i) * p * N;
      xi_2 += pow(nCount[i] - tCount, 2) / tCount;
   }
 
   if (xi_2 < XI_2)
      cout << endl << "Pearson test: " << xi_2 << " < " << XI_2 << " => true sequence" << endl;
   else
      cout << endl << "Pearson test: " << xi_2 << " > " << XI_2 << " => false sequence" << endl;
}
 
vector<int> geometricDistribution(double p, vector<int> geodist)
{
   srand(time(NULL));
 
   ofstream geo("Geometric distribution.txt");
 
   for (int i = 0; i < N; i++)
   {
      double r = rand();
 
      geodist[i] = int(log(r) / log(1 - p));
 
      geo << geodist[i] << endl;
   }
 
   geo.close();
 
   return geodist;
}
 
// Распределение Пуассона
 
void pearsonTestForPoisson(double mu, vector<int> poidist)
{
   sort(poidist.begin(), poidist.end());
 
   int max = poidist[N - 1];
 
   vector<int> nCount(max + 1, 0);
 
   double xi_2 = 0.0, XI_2 = calculateXi2ForPearsonTest(max);
 
   for (int i = 0; i < N; i++)
      ++nCount[poidist[i]];
 
   for (int i = 0; i <= max; i++)
   {
      double tCount = pow(mu, i) * exp(-mu) / calculateFactorial(i) * N;
      xi_2 += pow(nCount[i] - tCount, 2) / tCount;
   }
 
   if (xi_2 < XI_2)
      cout << endl << "Pearson test: " << xi_2 << " < " << XI_2 << " => true sequence" << endl;
   else
      cout << endl << "Pearson test: " << xi_2 << " > " << XI_2 << " => false sequence" << endl;
}
 
vector<int> poissonDistribution(double mu, vector<int> poidist)
{
   srand(time(NULL));
 
   ofstream poi("Poisson distribution.txt");
 
   for (int i = 0; i < N; i++)
   {
      int x = 0;
      double p = exp(-mu), r = rand();
 
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
 
   poi.close();
 
   return poidist;
}
 
 
int main()
{
   int n, m;
   double p, mu;
   vector<int> berdist(N, 0), bindist(N, 0), negbindist(N, 0), geodist(N, 0), poidist(N, 0);
 
   // Распределение Бернулли
 
   cout << "Bernoulli distribution" << endl << endl << "Please enter the bernoulli distribution parameter p (0 <= p <= 1)" << endl;
   cin >> p;
 
   berdist = bernoulliDistribution(p, berdist);
   pearsonTestForBernulli(p, berdist);
 
   // Биномиальное аспределение
 
   cout << endl;
   cout << "Binomial distribution" << endl << endl << "Please enter the binomial distribution parameters n (n > 0) and p (0 <= p <= 1)" << endl;
   cin >> n >> p;
 
   bindist = binomialDistribution(n, p, bindist);
   pearsonTestForBinomial(n, p, bindist);
 
   // Отрицательное биномиальное распределение
 
   cout << endl;
   cout << "Negative binomial distribution" << endl << endl << "Please enter the negative binomial distribution parameters m (m > 0) and p (0 <= p <= 1)" << endl;
   cin >> m >> p;
 
   negbindist = negBinomialDistribution(m, p, negbindist);
   pearsonTestForNegBinomial(m, p, negbindist);
 
   // Геометрическое распределение
 
   cout << endl;
   cout << "Geometric distribution" << endl << endl << "Please enter the geometric distribution parameter p (0 <= p <= 1)" << endl;
   cin >> p;
 
   geodist = geometricDistribution(p, geodist);
   pearsonTestForGeometric(p, geodist);
 
   // Распределение Пуассона
 
   cout << endl;
   cout << "Poisson distribution" << endl << endl << "Please enter the poisson distribution parameter mu" << endl;
   cin >> mu;
 
   poidist = poissonDistribution(mu, poidist);
   pearsonTestForPoisson(mu, poidist);
 
   return 0;
}
