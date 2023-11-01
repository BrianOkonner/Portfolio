// MFCfirststeps.h : main header file for the MFCFIRSTSTEPS application
//

#if !defined(AFX_MFCFIRSTSTEPS_H__AB0235B5_9F4F_4250_8FF2_05158649CC62__INCLUDED_)
#define AFX_MFCFIRSTSTEPS_H__AB0235B5_9F4F_4250_8FF2_05158649CC62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCfirststepsApp:
// See MFCfirststeps.cpp for the implementation of this class
//

class CMFCfirststepsApp : public CWinApp
{
public:
	CMFCfirststepsApp();
	

	

	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCfirststepsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCfirststepsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCFIRSTSTEPS_H__AB0235B5_9F4F_4250_8FF2_05158649CC62__INCLUDED_)
