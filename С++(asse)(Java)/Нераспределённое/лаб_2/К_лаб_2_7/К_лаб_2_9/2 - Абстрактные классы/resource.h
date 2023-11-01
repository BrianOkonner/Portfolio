#define	IDC_BUTTONGO	100001
#define	IDC_BUTTON1		100002
#define	IDC_BUTTON2		100003
#define	IDC_BUTTON3		100004
#define IDC_BUTTONCHK	100005
#define	IDC_STIN1		200001
#define	IDC_STIN2		200002
#define	IDC_STOUT1		200011
#define	IDC_EDIT1		300001
#define	IDC_EDIT2		300002
#define	IDC_LBOX1		400001
#define MAX_LENGTH		100

#include <afxwin.h>
#include <fstream>
#include "abslib.h"
class CMainWnd : public CFrameWnd
{
public: 
	CMainWnd();
	void OnButtonGo();
	void OnButton1();
	void OnButton2();
	void OnButton3();
	void OnButtonChk();
private:
	CButton		*Go, *Bt1, *Bt2, *Bt3, *BtChk;
	CStatic		*StIn1, *StIn2, *StOut;
	CEdit		*Ed1, *Ed2;
	CListBox	*Lst; 
	Stud1 s1;
	Stud2 s2;
	Stud3 s3;
	DECLARE_MESSAGE_MAP();

};

class CMainApp : public CWinApp
{
public:
	CMainApp() : CWinApp() {}
	BOOL InitInstance();
};


