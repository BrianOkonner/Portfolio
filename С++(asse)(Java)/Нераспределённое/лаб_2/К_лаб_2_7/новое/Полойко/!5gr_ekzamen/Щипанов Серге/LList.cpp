/*
*   ��������� �������� ��������� �������
*    1 ���� 5 ������
* 
*   21 ������ 2010
*/


#include "LList.h"
/*
* �����������
*/
LList::LList(void)
{
	pHead=NULL;
	pTail=NULL;
	n=0;
}
/*
* ����������
*/
LList::~LList(void)
{
	while(pHead)
		this->pop();
}
/*
* �������� �� ������� � ����� STL
*/
bool LList::is_emitry(){
if(!pHead)
return true;
return false;
}/*
 * ������� ���������� � ������
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
* ������� ������� �� ������
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
