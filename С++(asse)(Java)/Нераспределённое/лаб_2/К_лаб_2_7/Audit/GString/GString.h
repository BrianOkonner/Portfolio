#include "string.h"
#include "iostream.h"
class GString
{
protected:
	char * m_pchData; 
	int nDataLength;
	void Release();
public:
// Constructors
	GString();
	GString(const GString& stringSrc);
	GString(char * lpsz);
// Attributes & Operations
	// as an array of characters
	void SetAt(int nIndex, char ch);
	void Empty();                      // free up the data
	// overloaded assignment
	const GString& operator=(const GString& stringSrc);
	const GString& operator=(char * lpsz);
	// string concatenation
	friend GString operator+(const GString& string1,const GString& string2);
	friend GString operator+(const GString& string, char * lpsz);
	friend GString operator+(char * lpsz, const GString& string);
	// upper/lower/reverse conversion
	void MakeUpper();
	void MakeLower();
	// searching (return starting index, or -1 if not found)
	int Find(char ch) const;              
	int Find(char * lpszSub) const;      
	// input and output
	friend ostream& operator<<(ostream& ar, const GString& string);
	friend istream& operator>>(istream& ar, GString& string);
 int GetLength() const
	{ return nDataLength; }
 int IsEmpty() const
	{ return nDataLength == 0; }
 operator char *() const
	{ return m_pchData; }
 int Compare(char * lpsz) const
	{ return strcmp(m_pchData, lpsz); }    // MBCS/Unicode aware
 char GetAt(int nIndex) const
{	return m_pchData[nIndex];}
 char operator[](int nIndex) const
{	return m_pchData[nIndex];}
 bool friend operator==(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) == 0; }
 bool friend operator==(const GString& s1, char * s2)
	{ return s1.Compare(s2) == 0; }
 bool friend operator==(char * s1, const GString& s2)
	{ return s2.Compare(s1) == 0; }
 bool friend operator!=(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) != 0; }
 bool friend operator!=(const GString& s1, char * s2)
	{ return s1.Compare(s2) != 0; }
 bool friend operator!=(char * s1, const GString& s2)
	{ return s2.Compare(s1) != 0; }
 bool friend operator<(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) < 0; }
 bool friend operator<(const GString& s1, char * s2)
	{ return s1.Compare(s2) < 0; }
 bool friend operator<(char * s1, const GString& s2)
	{ return s2.Compare(s1) > 0; }
 bool friend operator>(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) > 0; }
 bool friend operator>(const GString& s1, char * s2)
	{ return s1.Compare(s2) > 0; }
 bool friend operator>(char * s1, const GString& s2)
	{ return s2.Compare(s1) < 0; }
 bool friend operator<=(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) <= 0; }
 bool friend operator<=(const GString& s1, char * s2)
	{ return s1.Compare(s2) <= 0; }
 bool friend operator<=(char * s1, const GString& s2)
	{ return s2.Compare(s1) >= 0; }
 bool friend operator>=(const GString& s1, const GString& s2)
	{ return s1.Compare(s2) >= 0; }
 bool friend operator>=(const GString& s1, char * s2)
	{ return s1.Compare(s2) >= 0; }
 bool friend operator>=(char * s1, const GString& s2)
	{ return s2.Compare(s1) <= 0; }
	~GString();
};
