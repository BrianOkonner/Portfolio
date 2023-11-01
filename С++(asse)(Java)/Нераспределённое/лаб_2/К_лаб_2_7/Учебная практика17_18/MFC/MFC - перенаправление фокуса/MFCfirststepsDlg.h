// MFCfirststepsDlg.h : header file
//

#if !defined(AFX_MFCFIRSTSTEPSDLG_H__BD700329_42AB_423B_BD22_E9064FC36EF5__INCLUDED_)
#define AFX_MFCFIRSTSTEPSDLG_H__BD700329_42AB_423B_BD22_E9064FC36EF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCfirststepsDlg dialog

class CMFCfirststepsDlg : public CDialog
{
// Construction
public:
	CMFCfirststepsDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CMFCfirststepsDlg)
	enum { IDD = IDD_MFCFIRSTSTEPS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCfirststepsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	//CStatusBar m_wndStatusBar;
	// Generated message map functions
	//{{AFX_MSG(CMFCfirststepsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnEllipse();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_MSG
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	// do presentation of symbolic input
	CString staticOutput;	
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCFIRSTSTEPSDLG_H__BD700329_42AB_423B_BD22_E9064FC36EF5__INCLUDED_)
