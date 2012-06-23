; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=NGADlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gamaze.h"
LastPage=0

ClassCount=9
Class1=CGamazeApp
Class2=CGamazeDoc
Class3=CGamazeView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX (English (U.S.))
Resource4=IDR_MAINFRAME (English (U.S.))
Class6=NGADlg
Resource5=IDR_DOCUMENT (English (U.S.))
Class7=CGaMType
Class8=CCreateNewDlg
Resource6=IDD_NEWDIALOG
Resource7=IDD_PROPPAGE_SMALL (English (U.S.))
Resource8=IDD_DIALOG1
Class9=CSetStep
Resource9=IDD_NEWDIALOG1

[CLS:CGamazeApp]
Type=0
HeaderFile=gamaze.h
ImplementationFile=gamaze.cpp
Filter=N

[CLS:CGamazeDoc]
Type=0
HeaderFile=gamazeDoc.h
ImplementationFile=gamazeDoc.cpp
Filter=N
LastObject=CGamazeDoc

[CLS:CGamazeView]
Type=0
HeaderFile=gamazeView.h
ImplementationFile=gamazeView.cpp
Filter=C
LastObject=CGamazeView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=gamaze.cpp
ImplementationFile=gamaze.cpp
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

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NEWDIALOG1]
Type=1
Class=NGADlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NPOP,edit,1350639744
Control4=IDC_STATIC,static,1342308352
Control5=IDC_RADIO1,button,1342242825
Control6=IDC_RADIO2,button,1342242825
Control7=IDC_RADIO3,button,1476395017
Control8=IDC_RADIO4,button,1342242825
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_MUTATE,edit,1350639744
Control12=IDC_STATIC,static,1342308352
Control13=IDC_DAW,edit,1350639744
Control14=IDC_STATIC,static,1342308352
Control15=IDC_DPEN,edit,1350639744
Control16=IDC_STATIC,static,1342308352
Control17=IDC_IDIR,edit,1350639744
Control18=IDC_STATIC,static,1342308352
Control19=IDC_GOAL,edit,1350639744

[CLS:NGADlg]
Type=0
HeaderFile=NGADlg.h
ImplementationFile=NGADlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_GOAL
VirtualFilter=dWC

[CLS:CGaMType]
Type=0
HeaderFile=GaMType.h
ImplementationFile=GaMType.cpp
BaseClass=CDocument
Filter=N
LastObject=CGaMType

[DLG:IDD_NEWDIALOG]
Type=1
Class=CCreateNewDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1476395017
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_RADIO2,button,1342177289
Control9=IDC_STATIC,static,1342308352

[CLS:CCreateNewDlg]
Type=0
HeaderFile=CreateNewDlg.h
ImplementationFile=CreateNewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCreateNewDlg
VirtualFilter=dWC

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CSetStep
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CSetStep]
Type=0
HeaderFile=SetStep.h
ImplementationFile=SetStep.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSetStep

[TB:IDR_DOCUMENT (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_APP_ABOUT
Command9=ID_StepGen
Command10=ID_Stop
Command11=ID_SETSTEP
CommandCount=11

[MNU:IDR_DOCUMENT (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_SETSTEP
Command15=ID_StepGen
Command16=ID_Stop
Command17=ID_VIEW_TOOLBAR
Command18=ID_VIEW_STATUS_BAR
Command19=ID_APP_ABOUT
CommandCount=19

[ACL:IDR_DOCUMENT (English (U.S.))]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

