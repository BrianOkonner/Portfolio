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
#include "stud.h"
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
	STUD<Stud1> s1;
	STUD<Stud2> s2;
	STUD<Stud3> s3;
	DECLARE_MESSAGE_MAP();

};

class CMainApp : public CWinApp
{
public:
	CMainApp() : CWinApp() {}
	BOOL InitInstance();
};


CMainWnd::CMainWnd()
{
	Create(NULL, "Lab 9.1", WS_OVERLAPPEDWINDOW);
	Go = new CButton();
	Bt1 = new CButton();
	Bt2 = new CButton();
	Bt3 = new CButton();
	BtChk = new CButton();
	StIn1 = new CStatic();
	StIn2 = new CStatic();
	StOut = new CStatic();
	Ed1 = new CEdit();
	Ed2 = new CEdit();
	Lst = new CListBox();

	Go->Create("����!", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(210,10,310,30), this, IDC_BUTTONGO);
	Bt1->Create("��������", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(480,60,590,80),this, IDC_BUTTON1);
	Bt2->Create("��� ����", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(480,80,590,100),this, IDC_BUTTON2);
	Bt3->Create("��������", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(480,100,590,120),this, IDC_BUTTON3);
	StIn1->Create("������ ����:", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(0,0,100,20), this, IDC_STIN1);
	StIn2->Create("������ ����:", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(0,20,100,40), this, IDC_STIN2);
	StOut->Create("��������:", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(0,40,500,60), this, IDC_STOUT1);
	Ed1->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(100,0,200,20), this, IDC_EDIT1);
	Ed2->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(100,20,200,40), this, IDC_EDIT2);
	Lst->Create(WS_CHILD | LBS_USETABSTOPS | WS_VISIBLE | WS_TABSTOP | LBS_NOTIFY | WS_VSCROLL | WS_HSCROLL | WS_BORDER, CRect(0,60,480,300), this, IDC_LBOX1);
	BtChk->Create("��������", WS_CHILD | WS_VISIBLE | SS_CENTER | BS_CHECKBOX, CRect(320,10,420,30), this, IDC_BUTTONCHK);

	Lst->SetTabStops(50);
	Ed1->SetLimitText(MAX_LENGTH);
	Ed1->ReplaceSel("stud1.txt");
	Ed2->SetLimitText(MAX_LENGTH);
	Ed2->ReplaceSel("stud2.txt");
}

void CMainWnd::OnButtonGo()
{
	char* name = new char [MAX_LENGTH + 1];
	Ed1->GetLine(0,name);
	name[MAX_LENGTH] = '\0';
	ifstream in1, in2;
	in1.open(name);
	Ed2->GetLine(0,name);
	name[MAX_LENGTH] = '\0';
	in2.open(name);
	delete[] name;
	if (!in1.is_open() || !in2.is_open()) 
	{
		AfxMessageBox("������� ������ ��� �����"); 
		in1.close(); in2.close(); 
		return;
	}
	if (BtChk->GetCheck() == BST_CHECKED)
	{
		s1.BinRead(in1);
		s2.BinRead(in2);
	}
	else
	{
		in1 >> s1;
		in2 >> s2;
	}
	in1.close();
	in2.close();
	s3 = StudDebt(s1, s2);
	s3.SortName();
	s3.ListBoxPrint(Lst);
	ofstream out1,out2;
	out1.open("stud3.txt");
	out1 << s3;
	out2.open("stud3",ios::binary);
	s3.BinWrite(out2);
	out1.close();
	out2.close();
}

void CMainWnd::OnButton1()
{
	s1.ListBoxPrint(Lst);
}

void CMainWnd::OnButton2()
{
	s2.ListBoxPrint(Lst);
}

void CMainWnd::OnButton3()
{
	s3.ListBoxPrint(Lst);
}

void CMainWnd::OnButtonChk()
{
	Ed1->SetSel(0,-1);
	Ed2->SetSel(0,-1);
	if (BtChk->GetCheck() == BST_CHECKED)
	{
		Ed1->ReplaceSel("stud1");
		Ed2->ReplaceSel("stud2");
	}
	else
	{
		Ed1->ReplaceSel("stud1.txt");
		Ed2->ReplaceSel("stud2.txt");
	}
}

BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_BN_CLICKED(IDC_BUTTONGO, OnButtonGo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTONCHK, OnButtonChk)
END_MESSAGE_MAP()

BOOL CMainApp::InitInstance()
{
	m_pMainWnd = new CMainWnd();
	ASSERT(m_pMainWnd);
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}