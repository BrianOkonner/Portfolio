#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

const int N = 1000;
const double KA = 1.35;
 
// Равномерное распределение
 
void kolmogorovTestForEven(double a, double b, vector<double> evendist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(evendist.begin(), evendist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = (evendist[i] - a) / (b - a);
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> evenDistribution(double a, double b, vector<double> evendist)
{
    srand(time(NULL));
 
    ofstream even("Even distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        evendist[i] = (b - a) * uniform() + a;
 
        even << evendist[i] << endl;
    }
 
    even.close();
 
    return evendist;
}
 
// Нормальное распределение
 
void kolmogorovTestForNormal(double mu, double sg_2, vector<double> normdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(normdist.begin(), normdist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = 0.5 * (1 + erf((normdist[i] - mu) / (sqrt(2.0 * sg_2))));
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> normalDistribution(double mu, double sg_2, vector<double> normdist)
{
    srand(time(NULL));
 
    ofstream norm("Normal distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        double temp = 0;
 
        for (int j = 0; j < 12; j++)
            temp += uniform();
        temp -= 6;
 
        normdist[i] = mu + sqrt(sg_2) * temp;
 
        norm << normdist[i] << endl;
    }
 
    norm.close();
 
    return normdist;
}
 
// Логнормальное распределение
 
void kolmogorovTestForLognormal(double mu, double sg_2, vector<double> lnormdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(lnormdist.begin(), lnormdist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = 0.5 + 0.5 * erf((log(lnormdist[i]) - mu) / (sqrt(2.0 * sg_2)));
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> lognormalDistribution(double mu, double sg_2, vector<double> lnormdist)
{
    srand(time(NULL));
 
    ofstream lnorm("Lognormal distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        double temp = 0;
 
        for (int j = 0; j < 12; j++)
            temp += uniform();
        temp -= 6;
 
        lnormdist[i] = exp(mu + sqrt(sg_2) * temp);
 
        lnorm << lnormdist[i] << endl;
    }
 
    lnorm.close();
 
    return lnormdist;
}
 
// Экспоненциальное распределение
 
void kolmogorovTestForExponential(double lm, vector<double> expdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(expdist.begin(), expdist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = 1.0 - exp(-lm * expdist[i]);
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> exponentialDistribution(double lm, vector<double> expdist)
{
    srand(time(NULL));
 
    ofstream ex("Exponential distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        expdist[i] = (-1.0 / lm) * log(uniform());
 
        ex << expdist[i] << endl;
    }
 
    ex.close();
 
    return expdist;
}
 
// Логистическое распределение
 
void kolmogorovTestForLogistic(double mu, double k, vector<double> logdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(logdist.begin(), logdist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = 1 / (1 + exp(-(logdist[i] - mu) / k));
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> logisticDistribution(double mu, double k, vector<double> logdist)
{
    srand(time(NULL));
 
    ofstream lg("Logistic distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        double temp = uniform();
 
        logdist[i] = mu + k * log(temp / (1.0 - temp));
 
        lg << logdist[i] << endl;
    }
 
    lg.close();
 
    return logdist;
}
 
// Распределение Лапласа
 
void kolmogorovTestForLaplas(double lm, vector<double> lapdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(lapdist.begin(), lapdist.end());
 
    for (int i = 0; i < N; i++)
    {
        if (lapdist[i] < 0)
            fotx = 0.5 * exp(lm * lapdist[i]);
        else
            fotx = 1 - 0.5 * exp(-lm * lapdist[i]);
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> laplasDistribution(double lm, vector<double> lapdist)
{
    srand(time(NULL));
 
    ofstream lap("Laplas distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        double temp = uniform();
 
        if (temp < 0.5)
            lapdist[i] = (1.0 / lm) * log(2 * temp);
        else
            lapdist[i] = (-1.0 / lm) * log(2 * (1 - temp));
 
        lap << lapdist[i] << endl;
    }
 
    lap.close();
 
    return lapdist;
}
 
// Распределение Коши
 
void kolmogorovTestForKoshi(double m, double c, vector<double> koshdist)
{
    double fotx, temp, d = 0.0, ka = sqrt(N);
 
    sort(koshdist.begin(), koshdist.end());
 
    for (int i = 0; i < N; i++)
    {
        fotx = 0.5 + 1.0 / M_PI * atan((koshdist[i] - m) / c);
 
        temp = fabs((double)(i + 1) / N - fotx);
 
        if (d < temp)
            d = temp;
    }
 
    ka *= d;
 
    if (ka < KA)
        cout << endl << "Kolmogorov test: " << ka << " < " << KA << " => true sequence" << endl;
    else
        cout << endl << "Kolmogorov test: " << ka << " > " << KA << " => false sequence" << endl;
}
 
vector<double> koshiDistribution(double m, double c, vector<double> koshdist)
{
    srand(time(NULL));
 
    ofstream kosh("Koshi distribution.txt");
 
    for (int i = 0; i < N; i++)
    {
        koshdist[i] = m + c * tan(M_PI * (uniform() - 0.5));
 
        kosh << koshdist[i] << endl;
    }
 
    kosh.close();
 
    return koshdist;
}
 
int main() {
    double a, b, mu, sg_2, lm, k, m, c;
    vector<double> evendist(N, 0), normdist(N, 0), lnormdist(N, 0), expdist(N, 0), logdist(N, 0), lapdist(N, 0), koshdist(N, 0);
 
    // Равномерное распределение
 
    cout << "Even distribution" << endl << endl << "Please, enter the even distribution parameters a and b (b > a)" << endl;
    cin >> a >> b;
 
    evendist = evenDistribution(a, b, evendist);
    kolmogorovTestForEven(a, b, evendist);
 
    // Нормальное распределение
 
    cout << endl;
    cout << "Normal distribution" << endl << endl << "Please, enter the normal distribution parameters mu and sigma^2 (sigma > 0)" << endl;
    cin >> mu >> sg_2;
 
    normdist = normalDistribution(mu, sg_2, normdist);
    kolmogorovTestForNormal(mu, sg_2, normdist);
 
    // Логнормальное распределение
 
    cout << endl;
    cout << "Lognormal distribution" << endl << endl << "Please, enter the lognormal distribution parameters mu and sigma^2 (sigma > 0)" << endl;
    cin >> mu >> sg_2;
 
    lnormdist = lognormalDistribution(mu, sg_2, lnormdist);
    kolmogorovTestForLognormal(mu, sg_2, lnormdist);
 
    // Экспоненциальное распределение
 
    cout << endl;
    cout << "Exponential distribution" << endl << endl << "Please, enter the exponential distribution parameter lambda (lambda > 0)" << endl;
    cin >> lm;
 
    expdist = exponentialDistribution(lm, expdist);
    kolmogorovTestForExponential(lm, expdist);
 
    // Логистическое распределение
 
    cout << endl;
    cout << "Logistic distribution" << endl << endl << "Please, enter the logistic distribution parameters mu and k (k > 0)" << endl;
    cin >> mu >> k;
 
    logdist = logisticDistribution(mu, k, logdist);
    kolmogorovTestForLogistic(mu, k, logdist);
 
    // Распределение Лапласа
 
    cout << endl;
    cout << "Laplas distribution" << endl << endl << "Please, enter the Laplas distribution parameter lambda (lambda > 0)" << endl;
    cin >> lm;
 
    lapdist = laplasDistribution(lm, lapdist);
    kolmogorovTestForLaplas(lm, lapdist);
 
    // Распределение Коши
 
    cout << endl;
    cout << "Koshi distribution" << endl << endl << "Please, enter the Koshi distribution parameters m and c (c > 0)" << endl;
    cin >> m >> c;
 
    koshdist = koshiDistribution(m, c, koshdist);
    kolmogorovTestForKoshi(m, c, koshdist);
 
    return 0;
}
