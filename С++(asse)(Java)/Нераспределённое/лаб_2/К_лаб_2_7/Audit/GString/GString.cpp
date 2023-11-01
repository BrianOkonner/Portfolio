#include "memory.h"
#include "gstring.h"
typedef unsigned short BYTE;
ostream& operator<<(ostream& ar, const GString& string)
{
	ar<<string.m_pchData;
	return ar;
}
istream& operator>>(istream& ar, GString& string)
{
	char zz[10000];
	ar.getline(zz,10000);
	if (string.nDataLength!=0)string.Release();
	string.m_pchData=_strdup(zz);
	string.nDataLength=strlen(zz);
	return ar;
}
//////////////////////////////////////////////////////////////////////////////
// Construction/Destruction

GString::GString()
{	nDataLength=0;m_pchData=NULL;	}

GString::GString(const GString& stringSrc)
{
	m_pchData=_strdup(stringSrc.m_pchData);
	nDataLength=stringSrc.nDataLength;
}

void GString::Release()
{			
	delete[]m_pchData;
	nDataLength=0;m_pchData=NULL;
}

void GString::Empty()
{
	if (nDataLength == 0)return;
	Release();
}

GString::~GString()
{
	if (nDataLength!= 0)delete[] m_pchData;
}

GString::GString(char * lpsz)
{
	m_pchData=_strdup(lpsz);
	nDataLength=strlen(lpsz);
}

const GString& GString::operator=(const GString& stringSrc)
{
	if (nDataLength != 0)Release();
	m_pchData=_strdup(stringSrc.m_pchData);
	nDataLength=stringSrc.nDataLength;
	return *this;
}

const GString& GString::operator=(char * lpsz)
{
	if (nDataLength != 0)Release();
	m_pchData=_strdup(lpsz);
	nDataLength=strlen(lpsz);
	return *this;
}

//////////////////////////////////////////////////////////////////////////////
// concatenation

GString operator+(const GString& string1, const GString& string2)
{
	int t1=string1.nDataLength;
	int t2=string2.nDataLength;
	int t3=t1+t2+1;
	char *ss=new char[t3];
	GString s(ss);s.m_pchData[0]='\0';
	strcat(s.m_pchData,string1.m_pchData);
	strcat(s.m_pchData,string2.m_pchData);
	return s;
}

GString operator+(const GString& string, char * lpsz)
{
	char *ss=new char[string.nDataLength+strlen(lpsz)+1];
	GString s(ss);s.m_pchData[0]='\0';
	strcat(s.m_pchData,string.m_pchData);
	strcat(s.m_pchData,lpsz);
	return s;
}

GString operator+(char * lpsz, const GString& string)
{
	char *ss=new char[string.nDataLength+strlen(lpsz)+1];
	GString s(ss);s.m_pchData[0]='\0';
	strcat(s.m_pchData,lpsz);
	strcat(s.m_pchData,string.m_pchData);
	return s;
}
///////////////////////////////////////////////////////////////////////////////
// Commonly used routines (rarely used routines in STREX.CPP)

int GString::Find(char ch) const
{
	// find first single character
	char* lpsz = strchr(m_pchData, ch);
	// return -1 if not found and index otherwise
	return (lpsz == NULL) ? -1 : (int)(lpsz - m_pchData);
}

void GString::MakeUpper()
{	strupr(m_pchData);}

void GString::MakeLower()
{	strlwr(m_pchData);}

void GString::SetAt(int nIndex, char ch)
{	m_pchData[nIndex] = ch;}

// find a sub-string (like strstr)
int GString::Find(char * lpszSub) const
{
	char* lpsz = strstr(m_pchData, lpszSub);
	return (lpsz == NULL) ? -1 : (int)(lpsz - m_pchData);
}
