class CScreenPos  
{
public:
	CScreenPos();
	virtual ~CScreenPos();
	CPoint GetPoint();
	void MovePoint(CPoint cp);
private:
	CPoint cpXY;
};
