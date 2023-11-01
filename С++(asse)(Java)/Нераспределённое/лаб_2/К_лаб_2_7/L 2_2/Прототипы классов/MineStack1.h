/*#if defined(__cplusplus)
#define STACK10   namespace Mstack {
 #define STACK1		}
#else
#define STACK10
#endif*/
#ifndef STACK10
#define STACK10
#include "typeinfo.h"
#include "stdafx.h"  //namespace Mstack {
template <class T> class Mstack
{
	int number;
	int head;
	T* stack;
public:
	Mstack();
	~Mstack();
	int push(T *el);
	T top();
	int size();
	T  *pop();
}; 
#include "MineStack1.cpp" 
