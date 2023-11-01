#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;
const int N = 10000;
const double KA = 1.35;
 

vector<double> normalDistribution(double mu, double sg_2, vector<double> normdist,double *mo, double *disp,double *omo, double *odisp)
{
    srand(time(NULL));
 
    ofstream norm("Normal distribution.txt");
	double temp = 0;
 
    for (int i = 0; i < N; i++)
    {
        temp = 0;
 
        for (int j = 0; j < 12; j++)
            temp += 0.1*(rand()%10);
        temp -= 6;
 
        normdist[i] = mu + sqrt(sg_2) * temp;
 
        norm << normdist[i] << endl;
    }
   (*omo)=0;
   *odisp=0;
   for (int i = 0; i < N; i++)
   {
	   (*omo)+=normdist[i];
   }
   *omo=*omo/N;
   for (int i = 0; i < N; i++)
   {
	   (*odisp)+=(normdist[i]-(*omo))*(normdist[i]-(*omo));
   }
   (*odisp)=(*odisp)/N;

    norm.close();
 
    return normdist;
}
 

 
vector<double> exponentialDistribution(double lm, vector<double> expdist,double *mo, double *disp,double *omo, double *odisp)
{
    srand(time(NULL));
 
    ofstream ex("Exponential distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        expdist[i] = (-1.0 / lm) * log(0.1*(rand()%10));
 
        ex << expdist[i] << endl;
    }
   (*omo)=0;
   *odisp=0;
   for (int i = 0; i < N; i++)
   {
	   (*omo)+=expdist[i];
   }
   *omo=*omo/N;
   for (int i = 0; i < N; i++)
   {
	   (*odisp)+=(expdist[i]-(*omo))*(expdist[i]-(*omo));
   }
   (*odisp)=(*odisp)/N;

    ex.close();
 
    return expdist;
}
 
// Логистическое распределение
 
 
vector<double> logisticDistribution(double mu, double k, vector<double> logdist,double *mo, double *disp,double *omo, double *odisp)
{
    srand(time(NULL));
 
    ofstream lg("Logistic distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        double temp = 0.1*(rand()%10);
 
        logdist[i] = mu + k * log(temp / (1.0 - temp));
 
        lg << logdist[i] << endl;
    }
   (*omo)=0;
   *odisp=0;
   for (int i = 0; i < N; i++)
   {
	   (*omo)+=logdist[i];
   }
   *omo=*omo/N;
   for (int i = 0; i < N; i++)
   {
	   (*odisp)+=(logdist[i]-(*omo))*(logdist[i]-(*omo));
   }
   (*odisp)=(*odisp)/N;

 
    lg.close();
 
    return logdist;
}
 
 
 
int main() 
{
    double a=0.5,  mu=0, sg_2=4., lm=0.5, k=1.5, m=-4.,mo,disp,omo,odisp;
    vector<double> evendist(N, 0), normdist(N, 0), lnormdist(N, 0), expdist(N, 0), logdist(N, 0), lapdist(N, 0), koshdist(N, 0);
 
    // Нормальное распределение
 
    cout << endl;
    cout << "Normal distribution" << endl;
 
    normdist = normalDistribution(m, sg_2, normdist,&mo,&disp,&omo,&odisp);
	cout << "Normal distribution realization in file \"Normal distribution.txt\""<< endl;
    cout << "Dispertion: "<<disp<< "   Otsenka Dispertion: " <<odisp<< "   Matematik Ozidanie: " <<mo<< "   Otsenka Matematik Ozidanie: " <<omo<< "   Oshibka Dispertion: " <<abs(disp-odisp)<<
	    "   Oshibka Matematik Ozidanie: " <<abs(mo-omo);

 
    // Экспоненциальное распределение
 
    cout << endl;
    cout << "Exponential distribution" << endl;
 
    expdist = exponentialDistribution(lm, expdist,&mo,&disp,&omo,&odisp);
	cout << "Exponential distribution realization in file \"Exponential distribution.txt\""<< endl;
    cout << "Dispertion: "<<disp<< "   Otsenka Dispertion: " <<odisp<< "   Matematik Ozidanie: " <<mo<< "   Otsenka Matematik Ozidanie: " <<omo<< "   Oshibka Dispertion: " <<abs(disp-odisp)<<
	    "   Oshibka Matematik Ozidanie: " <<abs(mo-omo);
 
    // Логистическое распределение
 
    cout << endl;
    cout << "Logistic distribution" << endl ;
 
    logdist = logisticDistribution(mu, k, logdist,&mo,&disp,&omo,&odisp);
	cout << "Logistic distribution realization in file \"Logistic distribution.txt\""<< endl;
    cout << "Dispertion: "<<disp<< "   Otsenka Dispertion: " <<odisp<< "   Matematik Ozidanie: " <<mo<< "   Otsenka Matematik Ozidanie: " <<omo<< "   Oshibka Dispertion: " <<abs(disp-odisp)<<
	    "   Oshibka Matematik Ozidanie: " <<abs(mo-omo);
 
	system("pause");
    return 0;
}
