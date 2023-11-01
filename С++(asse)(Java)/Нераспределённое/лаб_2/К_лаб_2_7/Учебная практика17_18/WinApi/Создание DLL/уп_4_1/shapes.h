//Беличенко Алексей 1 курс 7 группа
#include <windows.h>

class KShape
{
protected:
	bool isShown;
	KShape() {isShown = true;}
	KShape(const KShape& s) {isShown = s.isShown;}
public:
	virtual void Shift(int dx, int dy) = 0;
	virtual void MoveTo(const POINT&) = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void Rotate(double radian) = 0;
	virtual void Explode(double x) = 0;
	virtual POINT Center() = 0;
	virtual int Radius() = 0;
	void Show() {isShown = true;}
	void Hide() {isShown = false;}
};

class KCircle : public KShape
{
protected:
	POINT center;
	int rad;
	KCircle();
public:
	KCircle(int r, POINT c);
	KCircle(int r);
	KCircle(const KCircle&);
	int Radius() {return rad;}
	POINT Center() {return center;}
	void SetRad(int);
	void SetCenter(const POINT&);
	KCircle& operator = (const KCircle&);
	void Shift(int dx, int dy);
	void MoveTo(const POINT&);
	virtual void Draw(HDC hdc);
	void Rotate(double radian) {}
	void Explode(double x);
};

class KTriangle : public KShape
{
protected:
	POINT vertices[3];
	KTriangle();
public:
	KTriangle(POINT v1, POINT v2, POINT v3);
	KTriangle(const KTriangle&);
	int Radius();
	POINT Center();
	void SetRad(int);
	void SetCenter(const POINT&);
	KTriangle& operator = (const KTriangle&);
	void Shift(int dx, int dy);
	void MoveTo(const POINT&);
	virtual void Draw(HDC hdc);
	void Rotate(double radian);
	virtual void Explode(double x);
};

class KTriangleFilled : public KTriangle
{
protected: 
	int color;
	KTriangleFilled();
public:
	KTriangleFilled(POINT v1, POINT v2, POINT v3, int col);
	KTriangleFilled(const KTriangleFilled&);
	KTriangleFilled& operator = (const KTriangleFilled&);
	void SetColor(int col) {color = col;}
	virtual void Draw(HDC hdc);
};

class KCirclePartFilled : public KCircle
{
protected:
	int color;
	double angle1, angle2;
	KCirclePartFilled();
public:
	KCirclePartFilled(int r, POINT c, double a1, double a2, int col);
	KCirclePartFilled(const KCirclePartFilled&);
	KCirclePartFilled& operator = (const KCirclePartFilled&);
	void SetColor(int col) {color = col;}
	virtual void Draw(HDC hdc);
};

class KCirclePunched : public KCircle
{
protected:
	int radIn;
	KCirclePunched();
public:
	KCirclePunched(int r, POINT c, int rIn);
	KCirclePunched(const KCirclePunched&);
	KCirclePunched& operator = (const KCirclePunched&);
	void SetRadIn(int rIn) {radIn = rIn;}
	virtual void Draw(HDC hdc);
	virtual void Explode(double x);
};