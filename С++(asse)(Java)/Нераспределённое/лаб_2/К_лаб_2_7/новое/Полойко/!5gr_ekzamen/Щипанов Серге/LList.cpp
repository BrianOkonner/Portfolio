/*
*   программа написана Щипановым Сергеем
*    1 курс 5 группа
* 
*   21 января 2010
*/


#include "LList.h"
/*
* конструктор
*/
LList::LList(void)
{
	pHead=NULL;
	pTail=NULL;
	n=0;
}
/*
* деструктор
*/
LList::~LList(void)
{
	while(pHead)
		this->pop();
}
/*
* проверка на пустоту в стиле STL
*/
bool LList::is_emitry(){
if(!pHead)
return true;
return false;
}/*
 * функция добавления в список
 */
void LList::push(int a)
{
base *pTmp=pTail;
pTail=new base;
pTail->a=a;
pTail->pNext=NULL;
if(pTmp) pTmp->pNext=pTail;
if(!pHead)pHead=pTail;
++n;
}
/*
* функция взянтия из списка
*/
int LList::pop()
{

	base *pTmp=pHead;
	pHead=pHead->pNext;
	int a=pTmp->a;
	delete pTmp;
	--n;
	return a;

}
