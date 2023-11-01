class CZoomWindow  
{
public:
	CZoomWindow();
	virtual ~CZoomWindow();
	CSize GetWin();
	CSize GetView();
	void ZoomIn();
	void ZoomOut();
private:
	 CSize win;
	 CSize view;
};
