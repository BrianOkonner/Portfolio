#include <afxwin.h> // MFC �������� � ����������� ����������
#include <afxext.h> // MFC ����������
#include "ClassPolygon.h"
class KShape
{
protected:
	bool isShown;
	KShape() {isShown = true;}
	KShape(const KShape& s) {isShown = s.isShown;}
public:
	virtual void Shift(int dx, int dy) = 0;//������� �� � �
	virtual void MoveTo(const ClassPoint&) = 0;//����������� � �����
	virtual void Draw(CPaintDC &dc) = 0;//����������
	virtual void Rotate(double radian) = 0;//���������
	virtual void Explode(int x) = 0;//����������
	virtual ClassPoint Center() = 0;//����� ������
	virtual int Radius() = 0;//������ �������� ������
	void Show() {isShown = true;}//��������
	void Hide() {isShown = false;}//��������
};

class KCircle : public KShape//����������
{
protected:
	ClassPoint center;
	int R;
	KCircle();
public:
	KCircle(int r, ClassPoint c);
	KCircle(int r);
	KCircle(const KCircle&);
	int Radius() {return R;}
	ClassPoint Center() {return center;}
	void SetRad(int);
	void SetCenter(const ClassPoint&);
	KCircle& operator = (const KCircle&);
	void Shift(int dx, int dy);
	void MoveTo(const ClassPoint&);
	virtual void Draw(CPaintDC &dc);
	void Rotate(double radian) {}
	void Explode(int x);
};

class KTriangle : public KShape//�����������
{
protected:
	ClassPoint vertices[3];
	KTriangle();
public:
	KTriangle(ClassPoint v1, ClassPoint v2, ClassPoint v3);
	KTriangle(const KTriangle&);
	int Radius();
	ClassPoint Center();
	void SetRad(int);
	void SetCenter(const ClassPoint&);
	KTriangle& operator = (const KTriangle&);
	void Shift(int dx, int dy);
	void MoveTo(const ClassPoint&);
	virtual void Draw(CPaintDC &dc);
	void Rotate(double radian);
	virtual void Explode(int x);
};

class KTriangleFilled : public KTriangle//����������� �����������
{
protected: 
	int color;
	KTriangleFilled();
public:
	KTriangleFilled(ClassPoint v1, ClassPoint v2, ClassPoint v3, int col);
	KTriangleFilled(const KTriangleFilled&);
	KTriangleFilled& operator = (const KTriangleFilled&);
	void SetColor(int col) {color = col;}
	virtual void Draw(CPaintDC &dc);
};
class KCircleFilled : public KCircle//����������� ����������
{
protected: 
	int color;
	KCircleFilled();
public:
	KCircleFilled(int r, ClassPoint c, int col);
	KCircleFilled(const KCircleFilled&);
	KCircleFilled& operator = (const KCircleFilled&);
	void SetColor(int col) {color = col;}
	virtual void Draw(CPaintDC &dc);
};