// CreateNewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gamaze.h"
#include "CreateNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateNewDlg dialog


CCreateNewDlg::CCreateNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateNewDlg)
	m_FileName = _T("");
	//}}AFX_DATA_INIT
}


void CCreateNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateNewDlg)
	DDX_Text(pDX, IDC_EDIT1, m_FileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCreateNewDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateNewDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateNewDlg message handlers

void CCreateNewDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFileDialog FileName(TRUE);//The filename control method
	FileName.DoModal();//Display a modal dialoog form of this object
	m_FileName=FileName.GetPathName()+FileName.GetFileName();//Construct FFS
}

void CCreateNewDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_DocType=0;
}

void CCreateNewDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_DocType=1;
}
