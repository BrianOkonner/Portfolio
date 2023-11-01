#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <cmath>
#include <list>
#include <queue>
using namespace std;


void condition();

void menu();


//Josef
void Josef(const int, const int);


//From infix to postfix
#define MAX_LEN 256

void PostfixNotation(const char *, char *);
double calculation(const char*, const char *);
void condition1();
//sosedi
void sosedi();

//queues

void queue_func();
void print(queue<int>);
bool prost(int);
bool palindrom(char *);
#endif