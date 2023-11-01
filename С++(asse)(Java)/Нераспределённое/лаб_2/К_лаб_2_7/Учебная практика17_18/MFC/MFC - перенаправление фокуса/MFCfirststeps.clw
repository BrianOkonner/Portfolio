; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFCfirststepsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCfirststeps.h"

ClassCount=4
Class1=CMFCfirststepsApp
Class2=CMFCfirststepsDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFCFIRSTSTEPS_DIALOG
Resource4=IDR_MENU1
Resource5=IDD_CUSTOM_DIALOG
Resource6=IDD_FORMVIEW (English (U.S.))
Resource7=IDD_ABOUTBOX (English (U.S.))
Class4=CDlg
Resource8=IDD_MFCFIRSTSTEPS_DIALOG (English (U.S.))

[CLS:CMFCfirststepsApp]
Type=0
HeaderFile=MFCfirststeps.h
ImplementationFile=MFCfirststeps.cpp
Filter=N
LastObject=CMFCfirststepsApp

[CLS:CMFCfirststepsDlg]
Type=0
HeaderFile=MFCfirststepsDlg.h
ImplementationFile=MFCfirststepsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMFCfirststepsDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCfirststepsDlg.h
ImplementationFile=MFCfirststepsDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_MFCFIRSTSTEPS_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CMFCfirststepsDlg

[DLG:IDD_MFCFIRSTSTEPS_DIALOG (English (U.S.))]
Type=1
Class=CMFCfirststepsDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_STATIC_OUTPUT,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=CMFCfirststepsDlg
Command1=ID_PAINT_0
Command2=ID_PAINT_1
Command3=ID_MENU_DIALOG
Command4=ID_MENU_EXIT
CommandCount=4

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=CMFCfirststepsDlg
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_CUSTOM_DIALOG]
Type=1
Class=CDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlg]
Type=0
HeaderFile=Dlg.h
ImplementationFile=Dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg

